#include "random_movement.h"

void RandomMovement::move(int &x, int &y, const Map &gameMap, int, int) {
    int dx = (rand() % 3) - 1;
    int dy = (rand() % 3) - 1;

    if (gameMap.isValidMove(x + dx, y + dy)) {
        x += dx;
        y += dy;
    }
}
