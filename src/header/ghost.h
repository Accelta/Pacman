#ifndef GHOST_H
#define GHOST_H

#include "movement_strategy.h"

class Ghost {
private:
    int x, y;
    MovementStrategy* strategy;
public:
    Ghost(int startX, int startY, MovementStrategy* movement);
    void move(const Map &gameMap, int targetX, int targetY);
    int getX() const;
    int getY() const;
    void setStrategy(MovementStrategy* newStrategy);
};

#endif
