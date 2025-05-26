#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.AllNightMaskNoTimeSkip"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterAllNightMaskNoTimeSkip() {
    COND_VB_SHOULD(VB_ALL_NIGHT_TIME_SKIP, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterAllNightMaskNoTimeSkip, { CVAR_NAME });
