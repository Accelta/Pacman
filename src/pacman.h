#ifndef PACMAN_H
#define PACMAN_H

class Map; // Forward declaration (fixes circular dependency)

class Pacman {
public:
    int x, y;
    
    Pacman(int startX, int startY);
    void move(int dx, int dy, Map &gameMap);
};

#endif
