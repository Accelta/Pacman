// #ifndef GHOST_H
// #define GHOST_H

// // #include "movement_strategy.h"
// #include "ghost_state.h"
// class Ghost {
// private:
//     int x, y;
//     GhostState *state;
// public:
//     Ghost(int startX, int startY, GhostState *initialstate);
//     ~Ghost();
//     void move(const Pacman &pacman, const Map &gameMap);
//     void changeState(GhostState *newState);
//     int getX() const{return x;};
//     int getY() const{return y;};
//     void setPosition(int newX, int newY) {x =newX; y =newY;};
// };

// #endif
#ifndef GHOST_H
#define GHOST_H

#include <iostream>

class GhostState; // Forward declaration
class Pacman; // Forward declaration
class Map; // Forward declaration

class Ghost {
private:
    int x, y;
    GhostState *state;

public:
    Ghost(int startX, int startY, GhostState *initialState);
    ~Ghost();

    void move(const Pacman &pacman, const Map &gameMap);
    void changeState(GhostState *newState);
    
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
};

#endif
