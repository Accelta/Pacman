#ifndef MOVEMENT_STRATEGY_H
#define MOVEMENT_STRATEGY_H

#include "map.h"

class MovementStrategy {
public:
    virtual ~MovementStrategy() = default;
    virtual void move(int &x, int &y, const Map &gameMap, int targetX, int targetY) = 0;
};

#endif
