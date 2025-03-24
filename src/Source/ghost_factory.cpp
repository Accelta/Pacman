// #include "ghost_factory.h"

// Ghost* GhostFactory::createGhost(int x, int y, int type) {
//     if (type == 0) return new Ghost(x, y, new ChasingMovement());  // Fast ghost
//     if (type == 1) return new Ghost(x, y, new RandomMovement());   // Slower ghost
//     return nullptr;
// }

#include "ghost_factory.h"

Ghost* GhostFactory::createGhost(GhostType type, int x, int y) {
    switch (type) {
        case BLINKY: return new Ghost(x, y, new ChaseState());
        case PINKY: return new Ghost(x, y, new WanderState());
        case INKY: return new Ghost(x, y, new FrightenedState());
        case CLYDE: return new Ghost(x, y, new ReturnToBaseState());
        default: return nullptr;
    }
}
