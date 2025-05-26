#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.MayorArguesUntilMoonfall"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterMayorArguesUntilMoonfall() {
    COND_VB_SHOULD(VB_MAYOR_STOP_ARGUING, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterMayorArguesUntilMoonfall, { CVAR_NAME });
