#include "ghost_factory.h"

Ghost* GhostFactory::createGhost(int x, int y, int type) {
    if (type == 0)
        return new Ghost(x, y, new ChasingMovement());
    else
        return new Ghost(x, y, new RandomMovement());
}
