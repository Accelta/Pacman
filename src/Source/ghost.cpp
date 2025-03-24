// #include "ghost.h"

// Ghost::Ghost(int startX, int startY, MovementStrategy* movement)
//     : x(startX), y(startY), strategy(movement) {}

// void Ghost::move(const Map &gameMap, int targetX, int targetY) {
//     if (strategy) {
//         strategy->move(x, y, gameMap, targetX, targetY);
//     }
// }

// int Ghost::getX() const { return x; }
// int Ghost::getY() const { return y; }

// void Ghost::setStrategy(MovementStrategy* newStrategy) {
//     strategy = newStrategy;
// }
#include "ghost.h"
#include"ghost_state.h"

Ghost::Ghost(int startX, int StartY, GhostState *initialstate)
:x(startX), y(StartY), state(initialstate) {}

Ghost::~Ghost() {delete state;}

void Ghost::move(const Pacman &pacman, const Map &gamemap){
    if (state) state->move(*this, pacman, gamemap);
}

void Ghost::changeState(GhostState *newstate){
    delete state;
    state = newstate;
}