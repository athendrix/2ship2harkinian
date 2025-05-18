#include <libultraship/bridge.h>
#include "2s2h/GameInteractor/GameInteractor.h"

void RegisterAllNightMaskWithBankMoney() {
    REGISTER_VB_SHOULD(VB_NOT_OVERFLOW_BANK, {
        if (CVarGetInteger("gEnhancements.Cycle.AllNightMaskWithBankMoney", 0)) {
            *should = false;
        }
    });
}
