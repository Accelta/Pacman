#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
// Don't include map.h here to prevent circular dependency
class Map; // Forward declaration

class Pacman {
private:
    int x, y;

public:
    Pacman(int startX, int startY) : x(startX), y(startY) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void move(int dx, int dy, const Map &gameMap);
};

#endif
