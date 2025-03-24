// #ifndef GHOST_FACTORY_H
// #define GHOST_FACTORY_H

// #include "ghost.h"
// #include "chasing_movement.h"
// #include "random_movement.h"

// enum GhostType { CHASER, RANDOM };

// class GhostFactory {
// public:
//     static Ghost* createGhost(GhostType type, int startX, int startY) {
//         switch (type) {
//             case CHASER:
//                 return new Ghost(startX, startY, new ChasingMovement());
//             case RANDOM:
//                 return new Ghost(startX, startY, new RandomMovement());
//             default:
//                 return nullptr;
//         }
//     }
// };

// #endif
// #ifndef GHOST_FACTORY_H
// #define GHOST_FACTORY_H

// #include "ghost.h"
// #include "chasing_movement.h"
// #include "random_movement.h"

// class GhostFactory {
// public:
//     static Ghost* createGhost(int x, int y, int type);
// };

// #endif

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
