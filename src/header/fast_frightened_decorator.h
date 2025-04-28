#ifndef FAST_FRIGHTENED_DECORATOR_H
#define FAST_FRIGHTENED_DECORATOR_H

#include "ghost_decorator.h"
#include <chrono>
#include <thread>

class FastFrightenedDecorator : public GhostDecorator {
public:
    FastFrightenedDecorator(GhostState* state) : GhostDecorator(state) {}

    void move(Ghost& ghost, const Pacman& pacman, const Map& gameMap) override {
        // Move twice per tick for fast effect
        wrappedState->move(ghost, pacman, gameMap);
        wrappedState->move(ghost, pacman, gameMap); 
    }
};

#endif
