#include "return_to_base_state.h"
#include "ghost.h"
#include "map.h"

void ReturnToBaseState::move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) {
    // Move towards the ghost house (assumed to be at (5,5))
    int dx = (5 > ghost.getX()) ? 1 : -1;
    int dy = (5 > ghost.getY()) ? 1 : -1;

    if (gameMap.isValidMove(ghost.getX() + dx, ghost.getY())) {
        ghost.setPosition(ghost.getX() + dx, ghost.getY());
    }
    if (gameMap.isValidMove(ghost.getX(), ghost.getY() + dy)) {
        ghost.setPosition(ghost.getX(), ghost.getY() + dy);
    }
}
