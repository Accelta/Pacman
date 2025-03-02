#include "map.h"
#include <iostream>

Map::Map() {
    char temp[height][width] = {
        "##########",
        "#........#",
        "#.######.#",
        "#........#",
        "#.######.#",
        "#........#",
        "#.######.#",
        "#........#",
        "#........#",
        "##########"
    };

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = temp[i][j];
        }
    }
}

void Map::render(const Pacman &player, const Ghost &ghost) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (player.x == i && player.y == j)
                std::cout << 'P';
            else if (ghost.x == i && ghost.y == j)
                std::cout << 'G';
            else
                std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

bool Map::isValidMove(int x, int y) {
    return grid[x][y] != '#';
}
