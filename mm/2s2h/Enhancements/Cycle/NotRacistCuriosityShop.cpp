#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

void RegisterNotRacistCuriosityShop() {
    REGISTER_VB_SHOULD(VB_CURIOSITY_SHOP_RACIST, {
        if (CVarGetInteger("gEnhancements.Cycle.NotRacistCuriosityShop", 0)) {
            *should = false;
        }
    });
}
