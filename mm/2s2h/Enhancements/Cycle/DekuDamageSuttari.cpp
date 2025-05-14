#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

void RegisterDekuDamageSuttari() {
    REGISTER_VB_SHOULD(VB_SUTTARI_IMMUNE_DEKU, {
        if (CVarGetInteger("gEnhancements.Cycle.DekuDamageSuttari", 0)) {
            *should = false;
        }
    });
}
