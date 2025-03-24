#ifndef CHASING_MOVEMENT_H
#define CHASING_MOVEMENT_H

#include "movement_strategy.h"

class ChasingMovement : public MovementStrategy {
public:
    void move(int &x, int &y, const Map &gameMap, int targetX, int targetY) override;
};

#endif
