#include <common.h>
#include <utils.h>
#include <elf.h>
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);


#ifdef CONFIG_ITRACE
    iringbuf irb;
#endif

void iringbuf_inst(uint32_t pc,uint32_t inst){
    irb.pc[irb.irb_w] = pc;
    irb.inst[irb.irb_w] = inst;
    irb.irb_w = (irb.irb_w + 1) % IRINGBUF_MAX;
    if(irb.irb_w == irb.irb_r){
        irb.irb_r = (irb.irb_r + 1) % IRINGBUF_MAX;
    } 
}


void iringbuf_display(){
    char logbuf[64];
    while(irb.irb_r != irb.irb_w){
        char *p = logbuf;
        size_t remain = sizeof(logbuf); // 当前剩余空间

        if((irb.irb_r + 1) % IRINGBUF_MAX == irb.irb_w){
            int len = snprintf(p, remain, "--->");
            p += len;
            remain -= len;
        }else{
            memset(p,' ',4);
            p += 4;
            remain -= 4;
        }

        // 传入剩余空间remain，不再传sizeof(logbuf)
        int len = snprintf(p, remain, "%d:", irb.pc[irb.irb_r]);
        p += len;
        remain -= len;

        uint8_t *inst = (uint8_t *)&irb.inst[irb.irb_r];
        for(int i = 3;i >= 0; i--){
            len = snprintf(p, remain, " %02x", inst[i]);
            p += len;
            remain -= len;
        }

        memset(p,' ',4);
        p += 4;
        remain -= 4;

        // disassemble 原有剩余长度计算不变，逻辑正确
        disassemble(p, logbuf + sizeof(logbuf) - p, irb.pc[irb.irb_r], (uint8_t *)&irb.inst[irb.irb_r], 4);
        Log("%s\n", logbuf);
        irb.irb_r = (irb.irb_r + 1) % IRINGBUF_MAX;
    }
}

void display_pread(paddr_t addr, int len) {
    printf("mread at " FMT_PADDR " len=%d\n", addr, len);
}
  
void display_pwrite(paddr_t addr, int len, word_t data) {
    printf("mwrite at " FMT_PADDR " len=%d, data=" FMT_WORD "\n", addr, len, data);
}

#ifdef CONFIG_FTRACE
    symbol_table *symbol_tables;

int call_depth;
uint32_t symbol_tables_size;

void init_ftrace(const char *elf_file){
    if(elf_file == NULL){return;}
    // 打开ELF文件
    FILE *fp = fopen(elf_file,"rb+");
    Assert(fp,"can not open %s\n",elf_file);
    // 读取ELF header
    Elf32_Ehdr elf_header;
    if(fread(&elf_header,sizeof(Elf32_Ehdr),1,fp) <= 0){
        fclose(fp);
        Assert(0,"can not read elf_header\n");
    }
    // 检查文件是否为ELF文件
    if(memcmp(elf_header.e_ident,ELFMAG,SELFMAG) != 0){
        fclose(fp);
        Assert(0,"this isn't elf format\n");
    }
    // 移动到Section header table,寻找字符表节
    fseek(fp,elf_header.e_shoff,SEEK_SET);
    Elf32_Shdr elf_section_header;
    while(1){
        if(fread(&elf_section_header,sizeof(Elf32_Shdr),1,fp) <= 0){
            fclose(fp);
            Assert(0,"can not read elf_section_header\n");
        }
        if(elf_section_header.sh_type == SHT_STRTAB){
            break;
        }
    }
    // 读取字符串表内容
    char *string_table = malloc(elf_section_header.sh_size);
    fseek(fp,elf_section_header.sh_offset,SEEK_SET);
    if(fread(string_table,elf_section_header.sh_size,1,fp) <= 0){
        fclose(fp);
        free(string_table);
        Assert(0,"can not read string_table\n");
    }
    // 读取符号表中的每个符号项
    Elf32_Shdr sym_header;
    fseek(fp,elf_header.e_shoff,SEEK_SET);
    while(1){
        if(fread(&sym_header,sizeof(Elf32_Shdr),1,fp) <= 0){
            fclose(fp);
            free(string_table);
            Assert(0,"no sym_table\n");
        }
        else if(sym_header.sh_type == SHT_SYMTAB){
            break;
        }
    }
   
    if(sym_header.sh_entsize == 0){
        printf("no sh_entsize\n");
        fclose(fp);
        free(string_table);
        return;
    }

    Elf32_Sym elf_strtab;
    fseek(fp,sym_header.sh_offset,SEEK_SET);
    size_t num_str = sym_header.sh_size / sym_header.sh_entsize;
    symbol_tables = malloc(num_str * sizeof(symbol_table));

    for(int i = 0;i < num_str;i++){
        if(fread(&elf_strtab,sizeof(Elf32_Sym),1,fp) <= 0){
            fclose(fp);
            Assert(0,"can not read elf_strtab\n");
        }
        if(ELF32_ST_TYPE(elf_strtab.st_info) == STT_FUNC && elf_strtab.st_size != 0){
              char *name = string_table + elf_strtab.st_name;
              strncpy(symbol_tables[i].name,name,sizeof(symbol_tables[i].name)-1);
              symbol_tables[i].addr = elf_strtab.st_value;
              symbol_tables[i].info = elf_strtab.st_info;
              symbol_tables[i].size = elf_strtab.st_size;
        }
        symbol_tables_size = num_str;
    }
    fclose(fp);
    free(string_table);

}

void call_ftrace(paddr_t pc,paddr_t dnpc){
    if(symbol_tables == NULL) return;

    call_depth++;
    int i = find_symbol_func(dnpc,true);
    printf(FMT_PADDR ":%*scall [%s@" FMT_PADDR "]\n",
		pc,
		call_depth, "",
		i>0?symbol_tables[i].name:"???",
    dnpc);
}

void ret_ftrace(paddr_t pc){
    if(symbol_tables == NULL) return;

    int i = find_symbol_func(pc,false);
    printf(FMT_PADDR ":%*sret [%s]\n",
		pc,
		call_depth, "",
		i>0?symbol_tables[i].name:"???");
    call_depth--;
    if(strcmp(symbol_tables[i].name,"main") == 0){
        printf("call_depth is %d\n",call_depth);
    }
}

int find_symbol_func(paddr_t target, bool is_call) {
	int i;
	for (i = 0; i < symbol_tables_size; i++) {
		if (ELF32_ST_TYPE(symbol_tables[i].info) == STT_FUNC) {
			if (is_call) {
				if (symbol_tables[i].addr == target) break;
			} else {
				if (symbol_tables[i].addr <= target && target < symbol_tables[i].addr + symbol_tables[i].size) break;
			}
		}
	}
	return i<symbol_tables_size?i:-1;
}
#endif