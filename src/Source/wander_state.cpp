#include "wander_state.h"
#include "ghost.h"
#include "map.h"
#include <cstdlib>

void WanderState::move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) {
    int dx = (rand() % 3) - 1;  // -1, 0, or 1
    int dy = (rand() % 3) - 1;  

    if (gameMap.isValidMove(ghost.getX() + dx, ghost.getY() + dy)) {
        ghost.setPosition(ghost.getX() + dx, ghost.getY() + dy);
    }
}
