#ifndef CHASE_STATE_H
#define CHASE_STATE_H

#include "ghost_state.h"

class ChaseState : public GhostState {
public:
    void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) override;
};

#endif
