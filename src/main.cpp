#include <iostream>
#include <conio.h> // For _kbhit() and _getch() (Windows)
#include <windows.h> // Windows console functions
#include <thread>
#include <chrono>
#include "map.h"
#include "pacman.h"
#include "ghost.h"

// Hide the cursor in the console
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Move cursor to top-left instead of clearing screen
void moveCursorToTop() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos = {0, 0};
    SetConsoleCursorPosition(consoleHandle, cursorPos);
}

void gameLoop() {
    hideCursor(); // Hide cursor for smooth rendering

    Map gameMap;
    Pacman player(1, 1);
    Ghost ghost(3, 3);
    char input;

    while (true) {
        moveCursorToTop(); // Prevents screen flickering
        gameMap.render(player, ghost);

        if (_kbhit()) {
            input = _getch();

            switch (input) {
                case 'w': player.move(-1, 0, gameMap); break;
                case 's': player.move(1, 0, gameMap); break;
                case 'a': player.move(0, -1, gameMap); break;
                case 'd': player.move(0, 1, gameMap); break;
                case 'q': return; // Quit game
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust speed
    }
}

int main() {
    gameLoop();
    return 0;
}
