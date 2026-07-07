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
#include <memory/paddr.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

#define TOKENS_MAX 65536
bool check_parentheses(int p,int q);
uint32_t eval(int p,int q,bool *success);
int get_major(int p,int q);
enum {
  TK_NOTYPE = 256, TK_EQ,TK_NEQ,

  /* TODO: Add more token types */
  TK_ADD,TK_SUB,TK_MUL,TK_DIV,
  TK_LPAREN,TK_RPAREN,
  TK_NUM,
  TK_MINUS,
  TK_DEREF,
  TK_LE,TK_RE,TK_LEQ,TK_REQ,
  TK_AND,TK_OR,
  TK_REG,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {"==", TK_EQ},{"!=",TK_NEQ},
  {" +", TK_NOTYPE},
  {"\\+", TK_ADD},{"-", TK_SUB},{"\\*", TK_MUL},{"/", TK_DIV},
  {"\\(", TK_LPAREN},{"\\)", TK_RPAREN},
  {"(0x)?[0-9a-fA-F]+", TK_NUM},
  {"<",TK_LE},{">",TK_RE},{"<=",TK_LEQ},{">=",TK_REQ},
  {"&&",TK_AND},{"\\|\\|",TK_OR},
  {"\\$+\\w+",TK_REG},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[TOKENS_MAX] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
		case TK_NOTYPE: break;
		case TK_ADD:
		case TK_SUB:
		case TK_MUL:
		case TK_DIV:
		case TK_EQ:
		case TK_NEQ:
		case TK_LE:
		case TK_RE:
		case TK_LEQ:
		case TK_REQ:
		case TK_AND:
		case TK_OR:
		case TK_REG:
		case TK_LPAREN:
		case TK_RPAREN:
		case TK_NUM:if(nr_token < TOKENS_MAX){
				    tokens[nr_token].type = rules[i].token_type;
				    strncpy(tokens[nr_token].str,substr_start,substr_len);
				    tokens[nr_token].str[substr_len] = '\0';
				    nr_token++;
			    }
			    break;
          default: assert(0);
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}
static int deref_n[] = {TK_NUM,TK_RPAREN,TK_REG};

static bool judge_type(int type,int types[]){
  int num = 3;
  for(int i = 0;i<num;i++){
    if(type == types[i]){
      return true;
    }
  }
  return false;
}
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  
  for(int i = 0;i < nr_token-1;i++){
    if((i > 0 && tokens[i].type == TK_MUL && !judge_type(tokens[i-1].type,deref_n)) || (i == 0 && tokens[i].type == TK_MUL)){
      tokens[i].type = TK_DEREF;
    }
    else if((i > 0 && tokens[i].type == TK_SUB && !judge_type(tokens[i-1].type,deref_n)) || (i == 0 && tokens[i].type == TK_SUB)){
      tokens[i].type = TK_MINUS;
    }
  }
  /* TODO: Insert codes to evaluate the expression. */
  uint32_t ret = eval(0,nr_token-1,success);

  return ret;
}

bool check_parentheses(int p,int q){
	if(tokens[p].type!=TK_LPAREN || tokens[q].type!=TK_RPAREN) return false;
	else {
		int pnum = 0;
		for(int i = p;i <= q;i++){
			if(tokens[i].type == TK_LPAREN) pnum++;
			else if(tokens[i].type == TK_RPAREN) pnum--;
			if(pnum == 0 && i < q) return false;
		}
	}
	return true;
}

uint32_t eval(int p,int q,bool *success){
	if(p > q){
		*success = false;
		return 0;
	}
	else if(p == q){
		if(tokens[p].type==TK_NUM){
			if(strncmp("0x",tokens[p].str,2)==0){
				return strtol(tokens[p].str,NULL,16);
			}
			else return strtol(tokens[p].str,NULL,10);
		}
		else if(tokens[p].type == TK_REG){
			return isa_reg_str2val(tokens[p].str,success);
		}
		else{
			*success = false;
			return 0;
		}
	}
	else if(check_parentheses(p,q)==true){
		return eval(p+1,q-1,success);
	}
	else {
		int op = get_major(p,q);
		if(op < 0){
			*success = false;
			return 0;
		}
		
		bool success1 = true;
		bool success2 = true;
		int val1 = eval(p,op-1,&success1);
		//printf("val1 = %u\n",val1);
		int val2 = eval(op+1,q,&success2);
		//printf("val2 = %u\n",val2);

		if(success2 == false){
			*success = false;
		}
		
		if(success1){
			switch(tokens[op].type){
			case TK_OR:  return val1 || val2;
			case TK_AND: return val1 && val2;
			case TK_LEQ: return val1 <= val2;
			case TK_REQ: return val1 >= val2;
			case TK_LE:  return val1 < val2;
			case TK_RE:  return val1 > val2;
			case TK_EQ:  return val1 == val2;
			case TK_NEQ: return val1 != val2;
			case TK_ADD: return val1 + val2;
			case TK_SUB: return val1 - val2;
			case TK_MUL: return val1 * val2;
			case TK_DIV: if(val2 == 0){
					     *success = false;
				     }
				     else return val1 / val2;	     
			default:assert(0);
			}
		}
		else{
		switch(tokens[op].type){
			case TK_DEREF: return paddr_read(val2,4);
			case TK_MINUS: return -val2;	     
			default:assert(0);
			}
		}
	}
}

int get_major(int p,int q){
	int ret = -1,pnum = 0,pri = 0;
	for(int i = p;i <= q;i++){
		if(tokens[i].type == TK_NUM){
			continue;
		}
		if(tokens[i].type == TK_LPAREN){
			pnum++;
		}
		else if(tokens[i].type == TK_RPAREN){
			if(pnum == 0){
				return -1;          
			}
			pnum--;
		}
		else if(pnum > 0){
			continue;
		}
		else{
			int tmp_pri;
			switch(tokens[i].type){
				case TK_OR:tmp_pri = 6;break;
				case TK_AND:tmp_pri = 5;break;
				case TK_LEQ:tmp_pri = 4;break;
				case TK_REQ:tmp_pri = 4;break;
				case TK_LE: tmp_pri = 4;break;
				case TK_RE: tmp_pri = 4;break;
				case TK_EQ:tmp_pri = 4;break;
				case TK_NEQ:tmp_pri = 4;break;
				case TK_ADD:tmp_pri = 3;break;
				case TK_SUB:tmp_pri = 3;break;
				case TK_MUL:tmp_pri = 2;break;
				case TK_DIV:tmp_pri = 2;break;
				case TK_DEREF:tmp_pri = 1;break;
				case TK_MINUS:tmp_pri = 1;break;
				case TK_REG:tmp_pri = 1;break;
				default:assert(0);
			}
			if(tmp_pri > pri){
				pri = tmp_pri;
				ret = i;
			}
			else if(tmp_pri == pri){
				ret = i;
			}
		}
	}
	//printf("%d %s\n",ret,tokens[ret].str);
	if(pnum > 0) return -1;
	return ret;
}
