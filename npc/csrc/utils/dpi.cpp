#include "svdpi.h"
#include "utils.h"

extern "C" {

    void ebreak(){
        npc_state.state = NPC_END;
        npc_state.halt_ret = 0;
    }

}
