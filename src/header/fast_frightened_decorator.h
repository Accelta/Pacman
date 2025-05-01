#ifndef FAST_FRIGHTENED_DECORATOR_H
#define FAST_FRIGHTENED_DECORATOR_H

#include "ghost_decorator.h"
#include <chrono>
#include <thread>

// class FastFrightenedDecorator : public GhostDecorator {
// public:
//     FastFrightenedDecorator(GhostState* state) : GhostDecorator(state) {}

//     void move(Ghost& ghost, const Pacman& pacman, const Map& gameMap) override {
//         // Move twice per tick for fast effect
//         wrappedState->move(ghost, pacman, gameMap);
//         wrappedState->move(ghost, pacman, gameMap); 
//     }
// };
class FastFrightenedDecorator : public GhostState {
    private:
        GhostState* wrappedState;
    
    public:
        FastFrightenedDecorator(GhostState* state) : wrappedState(state) {}
        ~FastFrightenedDecorator() { delete wrappedState; }
    
        void move(Ghost& ghost, const Pacman& pacman, const Map& gameMap) override {
            // Misalnya: Pindahkan dua kali
            wrappedState->move(ghost, pacman, gameMap);
            wrappedState->move(ghost, pacman, gameMap);
        }
    
        bool isFrightened() const override {
            return wrappedState->isFrightened();  // Delegasikan ke state sebenarnya
        }
    };
#endif
