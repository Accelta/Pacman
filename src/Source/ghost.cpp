#include "ghost.h"
#include "ghost_state.h"
#include "frightened_state.h"
#include "chase_state.h"
#include "return_to_base_state.h"
#include "wander_state.h"
#include "pacman.h"

Ghost::Ghost(int startX, int startY, GhostState* initialState)
    : x(startX), y(startY), state(initialState), previouseState(nullptr) {}

Ghost::~Ghost() {
    delete state;
    delete previouseState;  // Cleanup old state too
}

void Ghost::move(const Pacman& pacman, const Map& gamemap) {
    if (state) state->move(*this, pacman, gamemap);
}

void Ghost::changeState(GhostState* newState) {
    if (dynamic_cast<FrightenedState*>(newState)) {
        // Save current state before becoming frightened
        if (state && !dynamic_cast<FrightenedState*>(state)) {
            if (previouseState) delete previouseState;  // prevent memory leak
            previouseState = state;  // don't delete current, reuse it
        } else {
            delete state;  // if already frightened, delete it
        }
        state = newState;
    } else {
        if (state) delete state;
        state = newState;
    }
}

void Ghost::updateState() {
    if (dynamic_cast<FrightenedState*>(state)) {
        delete state;
        state = previouseState ? previouseState : new WanderState();
        previouseState = nullptr;
        // std::cout << "Frightened state ended. Ghost reverted.\n";
    }
}

std::string Ghost::getSymbol() {
    if (dynamic_cast<FrightenedState*>(state)) return "\033[34mG\033[0m"; // Blue
    if (dynamic_cast<ChaseState*>(state)) return "\033[31mG\033[0m";     // Red
    if (dynamic_cast<ReturnToBaseState*>(state)) return "\033[37mG\033[0m"; // White
    return "\033[35mG\033[0m"; // Default Purple (Wander)
}

void Ghost::checkChase(const Pacman& pacman) {
    if (dynamic_cast<FrightenedState*>(state)) return;

    int dx = abs(pacman.getX() - x);
    int dy = abs(pacman.getY() - y);

    if (!isChasing && dx + dy <= 3) {  // Manhattan distance ≤ 3
        isChasing = true;
        chaseStartTime = std::chrono::steady_clock::now();
        changeState(new ChaseState());
    }
}

void Ghost::updateChaseState() {
    if (isChasing) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - chaseStartTime).count();

        if (elapsed >= 5) {
            isChasing = false;
            changeState(new WanderState());
        }
    }
}

bool Ghost::isFrightened() const {
    return dynamic_cast<FrightenedState*>(state) != nullptr;
}

void Ghost::sendToBase() {
    if (state) delete state;
    state = new ReturnToBaseState();
}