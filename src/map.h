#ifndef MAP_H
#define MAP_H

#include "ghost.h"
#include "pacman.h"

class Map {
private:
    static const int width = 11;
    static const int height = 11;
    char grid[height][width];

public:
    Map();
    void render(const Pacman &player, const Ghost &ghost);
    bool isValidMove(int x, int y); // Collision detection
};

#endif
