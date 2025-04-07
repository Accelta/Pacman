#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "pacman.h"
#include "ghost.h"
#include "map.h"
#include "ghost_factory.h"
#include <vector>
#include <chrono>

class GameManager {
private:
    Pacman player;
    std::vector<Ghost*> ghosts;
    Map gameMap;
    bool isFrightened;
    std::chrono::steady_clock::time_point frightenedStart;

public:
    GameManager();
    ~GameManager();
    void runGameLoop();
    void render();
    std::vector<Ghost*>& getGhosts() { return ghosts; }
};

#endif
