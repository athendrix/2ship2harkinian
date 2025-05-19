#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

void RegisterAllNightMaskNoTimeSkip() {
    REGISTER_VB_SHOULD(VB_ALL_NIGHT_TIME_SKIP, {
        if (CVarGetInteger("gEnhancements.Cycle.AllNightMaskNoTimeSkip", 0)) {
            *should = false;
        }
    });
}
