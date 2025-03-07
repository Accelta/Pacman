#include "chasing_movement.h"

void ChasingMovement::move(int &x, int &y, const Map &gameMap, int targetX, int targetY) {
    int dx = (targetX > x) ? 1 : (targetX < x) ? -1 : 0;
    int dy = (targetY > y) ? 1 : (targetY < y) ? -1 : 0;

    if (gameMap.isValidMove(x + dx, y + dy)) {
        x += dx;
        y += dy;
    }
}
