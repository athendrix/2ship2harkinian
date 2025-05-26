#include "public/bridge/consolevariablebridge.h"
#include "2s2h/GameInteractor/GameInteractor.h"
#include "2s2h/ShipInit.hpp"

#define CVAR_NAME "gEnhancements.DifficultyOptions.NotRacistCuriosityShop"
#define CVAR CVarGetInteger(CVAR_NAME, 0)

void RegisterNotRacistCuriosityShop() {
    COND_VB_SHOULD(VB_CURIOSITY_SHOP_RACIST, CVAR, { *should = false; });
}

static RegisterShipInitFunc initFunc(RegisterNotRacistCuriosityShop, { CVAR_NAME });
