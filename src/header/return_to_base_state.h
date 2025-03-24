#ifndef RETURN_TO_BASE_STATE_H
#define RETURN_TO_BASE_STATE_H

#include "ghost_state.h"

class ReturnToBaseState : public GhostState {
public:
    void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) override;
};

#endif
