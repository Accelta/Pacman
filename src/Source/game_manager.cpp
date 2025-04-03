// #include "game_manager.h"
// #include <iostream>
// #include <conio.h>  // Windows keyboard input
// #include <thread>
// #include <chrono>
// #include <vector>
// #include "map.h"
// #include "pacman.h"
// #include "ghost_factory.h"
// #include "frightened_state.h"

// #ifdef _WIN32
//     #define CLEAR_SCREEN "cls"
// #else
//     #define CLEAR_SCREEN "clear"
// #endif

// void hideCursor() { std::cout << "\e[?25l]"; }
// void showCursor() { std::cout << "\e[?25h]"; }

// GameManager::GameManager() : player(5, 5) { // Initialize Pacman at (5,5)
//     ghosts.push_back(GhostFactory::createGhost(BLINKY, 3, 3));
//     ghosts.push_back(GhostFactory::createGhost(PINKY, 7, 7));
// }

// GameManager::~GameManager() {
// for (Ghost* ghost : ghosts)
// {
//     delete ghost;
// }
// ghosts.clear();
// }

// void GameManager::runGameLoop() {
//     Map gameMap;
//     Pacman player(1, 1);
//     GameManager game;  // Create GameManager instance

//     hideCursor();  // Hide cursor

//     int ghostSpeed = 2;
//     int moveCounter = 0;

//     std::string lastRenderedMap = "";  // Store last rendered map

//     while (true) {
//         std::string currentMap = gameMap.getRenderedMap(player, game.getGhosts());

//         if (currentMap != lastRenderedMap) {  // Only redraw if map changed
//             std::cout << "\033[H]";  // Move cursor to the top (Unix escape code)
//             std::cout << currentMap;
//             lastRenderedMap = currentMap;
//         }

//         if (_kbhit()) {
//             char input = _getch();
//             switch (input) {
//                 case 'w': player.move(-1, 0, gameMap); break;
//                 case 's': player.move(1, 0, gameMap); break;
//                 case 'a': player.move(0, -1, gameMap); break;
//                 case 'd': player.move(0, 1, gameMap); break;
//                 case 'x': 
//                 for (Ghost* ghost : game.getGhosts()) delete ghost;
//                 game.getGhosts().clear();
//                     showCursor();
//                     return;
//             }
//              if (gameMap.getTile(player.getX(), player.getY()) == '*') {
//             for (Ghost* ghost : ghosts) {
//                 ghost->changeState(new FrightenedState());
//             }
//         }
//         }
//         // if (gameMap.getTile(player.getX(), player.getY()) == '*') {
//         //     for (Ghost* ghost : ghosts) {
//         //         ghost->changeState(new FrightenedState());
//         //     }
//         // }

//         moveCounter++;

//         if (moveCounter % ghostSpeed == 0) {
//             for (auto ghost : game.getGhosts()) {
//                 ghost->move(player, gameMap);
//             }
//         }

//         std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Control FPS
//     }
// }
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

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void hideCursor() { std::cout << "\e[?25l"; }
void showCursor() { std::cout << "\e[?25h"; }

GameManager::GameManager() : player(5, 5) { // Initialize Pacman at (5,5)
    ghosts.push_back(GhostFactory::createGhost(BLINKY, 3, 3));
    ghosts.push_back(GhostFactory::createGhost(PINKY, 7, 7));
}

GameManager::~GameManager() {
    for (Ghost* ghost : ghosts) {
        delete ghost;
    }
    ghosts.clear();
}

void GameManager::runGameLoop() {
    Map gameMap;
    hideCursor();  // Hide cursor

    int ghostSpeed = 2;
    int moveCounter = 0;
    std::string lastRenderedMap = "";  // Store last rendered map

    while (true) {
        std::string currentMap = gameMap.getRenderedMap(player, ghosts);

        if (currentMap != lastRenderedMap) {  // Only redraw if map changed
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

            // Only move if it's a valid position
            if (dx != 0 || dy != 0) {
                int newX = player.getX() + dx;
                int newY = player.getY() + dy;

                if (gameMap.isValidMove(newX, newY)) {
                    char tile = gameMap.getTile(newX, newY);
                    player.move(dx, dy, gameMap); // Fix: Use relative movement
                    player.eatPellet(tile);
                    gameMap.eatPellet(newX, newY);

                    // If Pac-Man eats a power pellet, change ghost states
                    if (tile == '*') {
                        std::cout << "\nPac-Man ate a power pellet! Ghosts are frightened!\n";
                        for (Ghost* ghost : ghosts) {
                            ghost->changeState(new FrightenedState());
                        }
                    }
                }
            }
        }

        moveCounter++;

        if (moveCounter % ghostSpeed == 0) {
            for (auto ghost : ghosts) {
                ghost->move(player, gameMap);
            }
        }

        std::cout << "\nScore: " << player.getScore() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Control FPS
    }
}
