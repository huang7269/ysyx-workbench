#ifndef _UTILS_H_
#define _UTILS_H_

#include <common.h>

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

typedef struct {
  int state;
  uint32_t halt_pc;
  uint32_t halt_ret;
} NPCState;

extern NPCState npc_state;

#endif
