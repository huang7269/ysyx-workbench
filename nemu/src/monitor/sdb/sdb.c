/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <config/watchpoint.h>
static int is_batch_mode = false;

void test_expr();
void init_regex();
void init_wp_pool();
void wp_print();
word_t paddr_read(paddr_t addr, int len);
/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args){
  int step = 1;
  char *arg = strtok(args," ");

  if(arg != NULL){
    char *p = arg;
    while(*p != '\0'){
      if(!isdigit(*p)){
        printf("Usage: si [num], num must be positive integer\n");
        return 0;
      }
      p++;
    }
    step = atoi(arg);
    if(step <= 0){
      printf("Step number must greater than 0\n");
      return 0;
    }
  }

  cpu_exec(step);
  return 0;
}

static int cmd_info(char *args) {
  if(args == NULL) {
    printf("Usage:info r OR w\n");
    return 0;
  }else{
  char *arg = strtok(args," ");
  if((strcmp(arg,"r")==0)){
    isa_reg_display();
   }
  else if((strcmp(arg,"w")==0)){
     wp_print();
   }
  else printf("No the function!\nPrint register status,Print monitoring point information,\"r\"or\"w\"\n");
  }
  return 0;
}

static int cmd_x(char *args) {
  if(args == NULL){
    printf("Usage:x n EXPR\n");
    return 0;
  }
  char *arg = strtok(args," ");
  if(arg == NULL){
    printf("Usage:x n EXPR\n");
    return 0;
  }
  int num = atoi(arg);
  char *expr = strtok(NULL," ");
  if(expr == NULL){
    printf("Usage:x n EXPR\n");
    return 0;
  }
  if(strtok(NULL," ")!=NULL){
    printf("Usage:x n EXPR\n");
    return 0;
  }
  paddr_t addr = strtol(expr,NULL,16);
  for(int i = 0;i < num;i++){
    printf("%-#20x%-#20x\n",addr +4*i,paddr_read(addr + 4*i,4));
  }
  return 0;
}

static int cmd_w(char *args) {
	if(args == NULL){
		printf("Usage:w EXPR\n");
		return 0;
	}
	bool ok = true;
	uint32_t res = expr(args,&ok);
	if(ok == false){
		printf("EXPR fault!\n");
	}
	else{
	  wp_recode(args,res);
	}
	return 0;
}

static int cmd_d(char *args){
	if(args == NULL){
		printf("Usage:d N\n");
	}
	else{
		int on = atoi(args);
		wp_remove(on);
	}
	return 0;
}

static int cmd_p(char *args){
	if(args == NULL){
		printf("Usage:p EXPR\n");
		return 0;
	} 
	static bool success_val = true;
	static bool *success = &success_val;
	uint32_t ret = expr(args,success);
	if(*success == false){
		printf("result is false\n");
    *success = true;
		return 0;
	}
	printf("%u\n",ret);
	return 0;
}

static int cmd_test(char *argc){
  if(argc != NULL){
    printf("test expr");
    return 0;
  }
  else{
    test_expr();
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },

  /* TODO: Add more commands */
  { "si", "Let the program execute N instructions in a single step and then suspend execution",cmd_si },
  { "info","Print register status,Print monitoring point information",cmd_info },
  { "w","Set monitoring point,Pause program execution when the value of expression EXPR changes.",cmd_w},
  { "d","Delete the monitoring point with sequence number N.",cmd_d},
  { "x","Find the value of the expression EXPR and use the result as the starting memory Address, output N consecutive 4 bytes in hexadecimal form",cmd_x},
  { "p","expression evaluation",cmd_p},
  { "test","test expr",cmd_test},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void test_expr(){
  FILE *fp = fopen("/home/anonymous/ysyx-workbench/nemu/tools/gen-expr/input","r");
  if(fp == NULL) perror("test_expr fail");
  uint32_t result;
  size_t len = 0;
  ssize_t read;
  char *formula = NULL;
  
  bool success = true;
  while(1){
    if((fscanf(fp,"%u",&result)==EOF)) break;
    read = getline(&formula,&len,fp);
    formula[read-1] = '\0';
    
    uint32_t ret = expr(formula,&success);
    
    assert(success);
    if(result != ret){
      printf("ret = %u,test = %u\n",ret,result);
      puts(formula);
    
      assert(0);
    }
  }
  Log("test_expr pass!");
  free(formula);
  fclose(fp);
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
