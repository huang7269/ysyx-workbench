#include "utils.h"

NPCState npc_state = { .state = NPC_STOP };

int is_exit_status() {
  return (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
}
