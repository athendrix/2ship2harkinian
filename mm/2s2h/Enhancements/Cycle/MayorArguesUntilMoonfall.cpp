#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

void RegisterMayorArguesUntilMoonfall() {
    REGISTER_VB_SHOULD(VB_MAYOR_STOP_ARGUING, {
        if (CVarGetInteger("gEnhancements.Cycle.MayorArguesUntilMoonfall", 0)) {
            *should = false;
        }
    });
}
