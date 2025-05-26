#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.DekuDamageSuttari"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterDekuDamageSuttari() {
    COND_VB_SHOULD(VB_SUTTARI_IMMUNE_DEKU, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterDekuDamageSuttari, { CVAR_NAME });
