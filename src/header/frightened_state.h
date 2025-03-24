#ifndef FRIGHTENED_STATE_H
#define FRIGHTENED_STATE_H

#include "ghost_state.h"

class FrightenedState : public GhostState {
public:
    void move(Ghost &ghost, const Pacman &pacman, const Map &gameMap) override;
};

#endif
