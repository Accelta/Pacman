#ifndef GHOST_FACTORY_H
#define GHOST_FACTORY_H

#include "ghost.h"
#include "chase_state.h"
#include "wander_state.h"
#include "frightened_state.h"
#include "return_to_base_state.h"

enum GhostType { BLINKY, PINKY, INKY, CLYDE };

class GhostFactory {
public:
    static Ghost* createGhost(GhostType type, int x, int y);
};

#endif
