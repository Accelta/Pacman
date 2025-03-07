#include "ghost.h"

Ghost::Ghost(int startX, int startY, MovementStrategy* movement)
    : x(startX), y(startY), strategy(movement) {}

void Ghost::move(const Map &gameMap, int targetX, int targetY) {
    if (strategy) {
        strategy->move(x, y, gameMap, targetX, targetY);
    }
}

int Ghost::getX() const { return x; }
int Ghost::getY() const { return y; }

void Ghost::setStrategy(MovementStrategy* newStrategy) {
    strategy = newStrategy;
}
