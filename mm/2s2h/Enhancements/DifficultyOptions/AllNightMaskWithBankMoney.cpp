#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.AllNightMaskWithBankMoney"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterAllNightMaskWithBankMoney() {
    COND_VB_SHOULD(VB_NOT_OVERFLOW_BANK, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterAllNightMaskWithBankMoney, { CVAR_NAME });
