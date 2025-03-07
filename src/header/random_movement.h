#ifndef RANDOM_MOVEMENT_H
#define RANDOM_MOVEMENT_H

#include "movement_strategy.h"
#include <cstdlib>

class RandomMovement : public MovementStrategy {
public:
    void move(int &x, int &y, const Map &gameMap, int targetX, int targetY) override;
};

#endif
