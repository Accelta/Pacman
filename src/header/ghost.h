#ifndef GHOST_H
#define GHOST_H

#include <iostream>
#include <chrono>

class GhostState; // Forward declaration
class Pacman; // Forward declaration
class Map; // Forward declaration

class Ghost {
private:
    int x, y;
    GhostState *state;
    GhostState* previouseState; // To keep track of the previous state
    bool isChasing = false;
    std::chrono::steady_clock::time_point chaseStartTime;

public:
    Ghost(int startX, int startY, GhostState *initialState);
    ~Ghost();

    void move(const Pacman &pacman, const Map &gameMap);
    void changeState(GhostState* newState) ;
    void updateState();
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
    void checkChase(const Pacman& pacman);
    void updateChaseState();
    bool isInChaseState() const { return isChasing; }
    std::string getSymbol();
    bool isFrightened() const;
    bool isReturning() const;
    void sendToBase();
};

#endif
