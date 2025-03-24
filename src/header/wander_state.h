#ifndef WANDER_STATE_H
#define WANDER_STATE_H

#include "ghost_state.h"

class WanderState : public GhostState {
public:
    void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) override;
};

#endif
