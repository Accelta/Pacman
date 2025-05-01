#include "return_to_base_state.h"
#include "ghost.h"
#include "map.h"
#include "wander_state.h"

// void ReturnToBaseState::move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) {
//     // Move towards the ghost house (assumed to be at (5,5))
//     int dx = (10 > ghost.getX()) ? 1 : -1;
//     int dy = (10 > ghost.getY()) ? 1 : -1;

//     if (gameMap.isValidMove(ghost.getX() + dx, ghost.getY())) {
//         ghost.setPosition(ghost.getX() + dx, ghost.getY());
//     }
//     if (gameMap.isValidMove(ghost.getX(), ghost.getY() + dy)) {
//         ghost.setPosition(ghost.getX(), ghost.getY() + dy);
//     }
// }
void ReturnToBaseState::move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) {
    const int baseX = 7;
    const int baseY = 9;

    int dx = 0;
    int dy = 0;

    if (ghost.getX() < baseX) dx = 1;
    else if (ghost.getX() > baseX) dx = -1;

    if (dx != 0 && gameMap.isValidMove(ghost.getX() + dx, ghost.getY())) {
        ghost.setPosition(ghost.getX() + dx, ghost.getY());
        return;  // Prioritize x movement
    }

    if (ghost.getY() < baseY) dy = 1;
    else if (ghost.getY() > baseY) dy = -1;

    if (dy != 0 && gameMap.isValidMove(ghost.getX(), ghost.getY() + dy)) {
        ghost.setPosition(ghost.getX(), ghost.getY() + dy);
        return;
    }

    // If at base, switch to WanderState
    if (ghost.getX() == baseX && ghost.getY() == baseY) {
        ghost.changeState(new WanderState());
    }
}
