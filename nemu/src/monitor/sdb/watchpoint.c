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

#include "sdb.h"
#include <cpu/cpu.h>
#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char *expr;
  uint32_t result;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

static WP* new_wp(){
  assert(free_);
  WP *ret = free_;
  
  free_ = free_->next;
  ret->next = head;

  head = ret;
  
  return ret;
}

static void free_wp(WP *wp){
  if(wp == NULL) return;

  WP *phead = head;
  if(phead == wp) head = head->next;
  else{
    while(phead!=NULL && phead->next!=wp){
      phead = phead->next;
    }
    if(phead == NULL){
      printf("Error: wp not found in the used list.\n");
      return;
    }
    phead->next = wp->next;
  }
    wp->next = free_;
    free_ = wp;
    free(wp->expr);
}

void wp_recode(char *args,uint32_t result){
  WP *phead = new_wp();
  phead->expr = strdup(args);
  phead->result = result;
  printf("Watchpoint:%d %s\n",phead->NO,phead->expr);
}

void wp_remove(int no){
  WP *phead = head;
  while(phead != NULL && phead->NO != no){
    phead = phead->next;
  }
  if(phead == NULL){
    printf("No the watchpoint\n");
  }
  else {
    free_wp(phead);
    printf("Delete the watchpoint NO:%d\n",no);
  }
  return; 
}

void wp_print(){
  WP *wp = head;
  if(wp == NULL){
    printf("No watchpoint.\n");
    return;
  }
  while(wp != NULL){
    printf("watchpoint NO:%-8d EXPR:%-20s result:%u\n",wp->NO,wp->expr,wp->result);
    wp = wp->next;
  }
}

void wp_difftest(){
  WP *wp = head;
  while(wp != NULL){
    bool wp_ok = true;
    uint32_t new = expr(wp->expr,&wp_ok);
    if(new != wp->result){
      nemu_state.state = NEMU_STOP;
      printf("watchpoint:%8d%20s\nold:%-20unew:%u\n",wp->NO,wp->expr,wp->result,new);
      wp->result = new;
      
    }
    wp = wp->next;
  }
}
