#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.OceansideWalletAnyDay"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterOceansideWalletAnyDay() {
    COND_VB_SHOULD(VB_OCEAN_HOUSE_WALLET_FIRST_DAY_ONLY, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterOceansideWalletAnyDay, { CVAR_NAME });
