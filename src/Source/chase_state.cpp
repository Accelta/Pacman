#include "chase_state.h"
#include "pacman.h"
#include "ghost.h"
#include "map.h"

void ChaseState::move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) {
    int dx = (pacman.getX() > ghost.getX()) ? 1 : -1;
    int dy = (pacman.getY() > ghost.getY()) ? 1 : -1;

    if (gameMap.isValidMove(ghost.getX() + dx, ghost.getY())) {
        ghost.setPosition(ghost.getX() + dx, ghost.getY());
    }
    if (gameMap.isValidMove(ghost.getX(), ghost.getY() + dy)) {
        ghost.setPosition(ghost.getX(), ghost.getY() + dy);
    }
}
