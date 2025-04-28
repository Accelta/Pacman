// #ifndef GHOST_STATE_H
// #define GHOST_STATE_H

// #include "ghost.h"
// #include "pacman.h"
// #include "map.h"

// class Ghost; // Forward declaration

// class GhostState {
// public:
//     virtual ~GhostState() {}
//     virtual void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) = 0;
// };

// #endif
#ifndef GHOST_STATE_H
#define GHOST_STATE_H

class Ghost; // Forward declaration
class Pacman; // Forward declaration
class Map; // Forward declaration

class GhostState {
public:
    virtual ~GhostState() {}
    virtual void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) = 0;
    virtual bool isFrightened() const { return false; }
};

#endif
