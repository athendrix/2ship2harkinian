#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.NoTimeskipAfterHideout"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterNoTimeskipAfterHideout() {
    COND_VB_SHOULD(VB_TIMESKIP_AFTER_HIDEOUT, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterNoTimeskipAfterHideout, { CVAR_NAME });
