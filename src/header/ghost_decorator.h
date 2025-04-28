#ifndef GHOST_DECORATOR_H
#define GHOST_DECORATOR_H

#include "ghost_state.h"

class GhostDecorator : public GhostState {
protected:
    GhostState* wrappedState;

public:
    GhostDecorator(GhostState* state) : wrappedState(state) {}
    virtual ~GhostDecorator() { delete wrappedState; }

    virtual void move(Ghost& ghost, const Pacman& pacman, const Map& gameMap) override {
        wrappedState->move(ghost, pacman, gameMap);
    }
    bool isFrightened() const override {
        return wrappedState->isFrightened();
    }
};

#endif
