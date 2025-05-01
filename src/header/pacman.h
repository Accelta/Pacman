#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
// Don't include map.h here to prevent circular dependency
class Map; // Forward declaration

class Pacman {
private:
    int x, y;
    int score;

public:
    Pacman(int startX, int startY) : x(startX), y(startY), score(0) {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getScore() const { return score; }

    void move(int dx, int dy, const Map &gameMap);
    void eatPellet(char tile);
    void addscore(int amount);
};

#endif
