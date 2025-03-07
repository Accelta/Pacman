// #include <iostream>
// #include <conio.h>
// #include <windows.h>
// #include <thread>
// #include <chrono>
// #include "map.h"
// #include "pacman.h"
// #include "ghost_factory.h"

// void hideCursor() {
//     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_CURSOR_INFO cursorInfo;
//     GetConsoleCursorInfo(consoleHandle, &cursorInfo);
//     cursorInfo.bVisible = FALSE;
//     SetConsoleCursorInfo(consoleHandle, &cursorInfo);
// }

// void moveCursorToTop() {
//     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//     COORD cursorPos = {0, 0};
//     SetConsoleCursorPosition(consoleHandle, cursorPos);
// }

// void gameLoop() {
//     hideCursor();

//     Map gameMap;
//     Pacman player(1, 1);
//     Ghost* ghost1 = GhostFactory::createGhost(CHASER, 5, 5);
//     Ghost* ghost2 = GhostFactory::createGhost(RANDOM, 7, 7);

//     char input;
//     while (true) {
//         moveCursorToTop();
//         gameMap.render(player, *ghost1);
//         gameMap.render(player, *ghost2);

//         if (_kbhit()) {
//             input = _getch();
//             switch (input) {
//                 case 'w': player.move(-1, 0, gameMap); break;
//                 case 's': player.move(1, 0, gameMap); break;
//                 case 'a': player.move(0, -1, gameMap); break;
//                 case 'd': player.move(0, 1, gameMap); break;
//                 case 'q': return;
//             }
//         }

//         ghost1->move(player, gameMap);
//         ghost2->move(player, gameMap);

//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }

//     delete ghost1;
//     delete ghost2;
// }

// int main() {
//     gameLoop();
//     return 0;
// }

// #include <iostream>
// #include <conio.h>  // Windows keyboard input
// #include <thread>
// #include <chrono>
// #include "map.h"
// #include "pacman.h"
// #include "ghost_factory.h"

// #ifdef _WIN32
//     #define CLEAR_SCREEN "cls"
// #else
//     #define CLEAR_SCREEN "clear"
// #endif

// void hideCursor() {
//     // Hide cursor for a smoother game loop
//     std::cout << "\e[?25l";
// }

// void showCursor() {
//     // Show cursor again when the game ends
//     std::cout << "\e[?25h";
// }

// void gameLoop() {
//     Map gameMap;
//     Pacman player(1, 1);
//     Ghost* ghost = GhostFactory::createGhost(5, 5, 0); // Type 0 = Chasing Ghost

//     hideCursor(); // Hide cursor at the start

//     while (true) {
//         system(CLEAR_SCREEN); // Efficient screen clearing

//         gameMap.render(player, *ghost);

//         if (_kbhit()) {
//             char input = _getch();
//             switch (input) {
//                 case 'w': player.move(-1, 0, gameMap); break;
//                 case 's': player.move(1, 0, gameMap); break;
//                 case 'a': player.move(0, -1, gameMap); break;
//                 case 'd': player.move(0, 1, gameMap); break;
//                 case 'x': delete ghost; showCursor(); return; // Exit game and restore cursor
//             }
//         }

//         ghost->move(gameMap, player.getX(), player.getY());

//         std::this_thread::sleep_for(std::chrono::milliseconds(200));
//     }
// }

// int main() {
//     gameLoop();
//     return 0;
// }
#include <iostream>
#include <conio.h>  // Windows keyboard input
#include <thread>
#include <chrono>
#include <vector>
#include "map.h"
#include "pacman.h"
#include "ghost_factory.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void hideCursor() { std::cout << "\e[?25l"; }
void showCursor() { std::cout << "\e[?25h"; }

void gameLoop() {
    Map gameMap;
    Pacman player(1, 1);

    // 🏴‍☠️ Create multiple ghosts
    std::vector<Ghost*> ghosts;
    ghosts.push_back(GhostFactory::createGhost(5, 5, 0)); // Chasing ghost
    ghosts.push_back(GhostFactory::createGhost(8, 8, 1)); // Random ghost

    hideCursor();  // Hide cursor

    int ghostSpeed = 2;  // 👻 Ghost moves every 2 player moves
    int moveCounter = 0;  // Counter for ghost movement delay

    while (true) {
        system(CLEAR_SCREEN);  // Clear screen efficiently

        // ✅ Render Pacman and ALL ghosts
        gameMap.render(player, ghosts);

        if (_kbhit()) {
            char input = _getch();
            switch (input) {
                case 'w': player.move(-1, 0, gameMap); break;
                case 's': player.move(1, 0, gameMap); break;
                case 'a': player.move(0, -1, gameMap); break;
                case 'd': player.move(0, 1, gameMap); break;
                case 'x': 
                    for (auto ghost : ghosts) delete ghost;
                    showCursor();
                    return;
            }
        }

        moveCounter++;  // 🏎️ Count player moves

        if (moveCounter % ghostSpeed == 0) {  // 👻 Slow down ghost movement
            for (auto ghost : ghosts) {
                ghost->move(gameMap, player.getX(), player.getY());
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Control FPS
    }
}

int main() {
    gameLoop();
    return 0;
}


