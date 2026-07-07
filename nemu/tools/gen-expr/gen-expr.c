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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define EXPR_MAX 20

// this should be enough
static char buf[65536] = {};
static char *buf_start = buf;
static char *buf_end = buf + sizeof(buf)/sizeof(buf[0]);
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static uint32_t choose(int n){
  return (uint32_t)(rand()%n);
}

static void gen_space(){
  int space_len = choose(5);
  if(buf_start < buf_end){
    int len = snprintf(buf_start,buf_end-buf_start,"%*s",space_len," ");
    buf_start = buf_start + len;
  }
}
static void gen_num(){
  uint32_t num = choose(EXPR_MAX);
  if(buf_start < buf_end){
    int len = snprintf(buf_start,buf_end-buf_start,"%u",num);
    buf_start = buf_start + len;
  }
  gen_space();
}

static void gen(char str){
  if(buf_start < buf_end){
    int len = snprintf(buf_start,buf_end-buf_start,"%c",str);
    buf_start = buf_start + len;
  }
}

static char op_types[]={'+','-','*','/'};
static void gen_rand_op(){
  int i = choose(4);
  if(buf_start < buf_end){
    int len = snprintf(buf_start,buf_end-buf_start,"%c",op_types[i]);
    buf_start = buf_start + len;
  }
  gen_space();
}

static void gen_rand_expr() {
  switch (choose(3)) {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
    }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf_start = buf;
    
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Wall -Werror -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint32_t result;
    ret = fscanf(fp, "%u", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
