#include "game_manager.h"
#include <iostream>
#include <conio.h>  // Windows keyboard input
#include <thread>
#include <chrono>
#include <vector>
#include "map.h"
#include "pacman.h"
#include "ghost_factory.h"
#include "frightened_state.h"
#include "fast_frightened_decorator.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void hideCursor() { std::cout << "\e[?25l"; }
void showCursor() { std::cout << "\e[?25h"; }

GameManager::GameManager() : player(5, 5), isFrightened(false) {
    ghosts.push_back(GhostFactory::createGhost(PINKY, 10, 5));
    ghosts.push_back(GhostFactory::createGhost(PINKY, 11, 8));
}

GameManager::~GameManager() {
    for (Ghost* ghost : ghosts) {
        delete ghost;
    }
    ghosts.clear();
}

void GameManager::runGameLoop() {
    Map gameMap;
    hideCursor();

    int ghostSpeed = 2;
    int moveCounter = 0;
    std::string lastRenderedMap = "";

    while (true) {
        std::string currentMap = gameMap.getRenderedMap(player, ghosts);

        if (currentMap != lastRenderedMap) {
            std::cout << "\033[H";  
            std::cout << currentMap;
            lastRenderedMap = currentMap;
        }

        if (_kbhit()) {
            char input = _getch();
            int dx = 0, dy = 0;

            switch (input) {
                case 'w': dx = -1; break;
                case 's': dx = 1; break;
                case 'a': dy = -1; break;
                case 'd': dy = 1; break;
                case 'x':
                    for (Ghost* ghost : ghosts) delete ghost;
                    ghosts.clear();
                    showCursor();
                    return;
            }

            if (dx != 0 || dy != 0) {
                int newX = player.getX() + dx;
                int newY = player.getY() + dy;

                if (gameMap.isValidMove(newX, newY)) {
                    char tile = gameMap.getTile(newX, newY);
                    player.move(dx, dy, gameMap);
                    player.eatPellet(tile);  // Update score based on tile type
                    gameMap.eatPellet(newX, newY);

                    if (tile == '*') {
                        // std::cout << "\nPac-Man ate a power pellet! Ghosts are frightened!\n";
                        frightenedStart = std::chrono::steady_clock::now();
                        isFrightened = true;
                        for (Ghost* ghost : ghosts) {
                            // ghost->changeState(new FrightenedState());
                            ghost->changeState(new FastFrightenedDecorator(new FrightenedState()));
                        }
                    }
                }
            }
        }

        for (Ghost* ghost : ghosts) {
            if (ghost->getX() == player.getX() && ghost->getY() == player.getY()) {
                if (ghost->isFrightened()) {
                    ghost->sendToBase();  // Change to ReturnToBaseState
                    player.addscore(200); // Reward score for eating ghost
                    
                    // Optional: print message
                    // std::cout << "Pac-Man ate a ghost!\n";
                } else {
                    // std::cout << "\nPacman was caught by a ghost! Game Over!\n";
                    // showCursor();
                }
            }
        }

        // Handle frightened state timing
        if (isFrightened) {
            auto now = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - frightenedStart).count();
            if (duration >= 5) {
                // std::cout << "\nFrightened state ended. Ghosts returning to previous states.\n";
                for (Ghost* ghost : ghosts) {
                    ghost->updateState();  // Revert to previous state
                }
                isFrightened = false;
            }
        }
        for (Ghost* ghost : ghosts) {
            if (!ghost->isReturning()|| ghost->isFrightened()) {  
                ghost->checkChase(player);      
                ghost->updateChaseState();      
            }
        }
        
        moveCounter++;

        if (moveCounter % ghostSpeed == 0) {
            for (auto ghost : ghosts) {
                ghost->move(player, gameMap);
            }
        }

        // std::cout << "\nScore: " << player.getScore() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Control FPS
    }
}

