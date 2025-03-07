// #include "map.h"
// #include "ghost.h"
// #include <iostream>

// Map::Map() {
//     char temp[height][width] = {
//         "##########",
//         "#........#",
//         "#.######.#",
//         "#........#",
//         "#.######.#",
//         "#........#",
//         "#.######.#",
//         "#........#",
//         "#........#",
//         "##########"
//     };

//     for (int i = 0; i < height; ++i) {
//         for (int j = 0; j < width; ++j) {
//             grid[i][j] = temp[i][j];
//         }
//     }
// }

// void Map::render(const Pacman &player, const Ghost &ghost) {
//     for (int i = 0; i < height; ++i) {
//         for (int j = 0; j < width; ++j) {
//             if (player.x == i && player.y == j)
//                 std::cout << 'P';
//             else if (ghost.x == i && ghost.y == j)
//                 std::cout << 'G';
//             else
//                 std::cout << grid[i][j];
//         }
//         std::cout << std::endl;
//     }
// }

// bool Map::isValidMove(int x, int y) const {
//     return grid[x][y] != '#';
// }
#include "map.h"
#include "ghost.h"

void Map::render(const Pacman &player, const std::vector<Ghost*>& ghosts) const {
    for (int i = 0; i < 10; i++) {  // Use fixed 10x10 size
        for (int j = 0; j < 10; j++) {
            if (i == player.getX() && j == player.getY()) {
                std::cout << "P";  // Pac-Man
            } else {
                bool ghostPrinted = false;
                for (const auto& ghost : ghosts) {
                    if (i == ghost->getX() && j == ghost->getY()) {
                        std::cout << "G";  // 👻 Print ghost
                        ghostPrinted = true;
                        break;  // Don't check other ghosts
                    }
                }
                if (!ghostPrinted) {
                    std::cout << grid[i][j];  // Render map
                }
            }
        }
        std::cout << "\n";
    }
}

