#include <iostream>
#include <conio.h> // Windows: _kbhit(), _getch()
#include <thread>
#include <chrono>
#include "map.h"
#include "pacman.h"
#include "ghost.h"

void gameLoop() {
    Map gameMap;
    Pacman player(1, 1);
    Ghost ghost(3, 3);
    char input;

    while (true) {
        system("cls"); // Clear screen (Windows)
        gameMap.render(player, ghost);

        if (_kbhit()) { // Check if a key is pressed
            input = _getch(); // Get key press
            
            switch (input) {
                case 'w': player.move(-1, 0, gameMap); break;
                case 's': player.move(1, 0, gameMap); break;
                case 'a': player.move(0, -1, gameMap); break;
                case 'd': player.move(0, 1, gameMap); break;
                case 'q': return; // Quit game
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add delay
    }
}

int main() {
    gameLoop();
    return 0;
}
