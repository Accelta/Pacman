#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "pacman.h" // Already includes Pacman
#include <vector> // Include vector for multiple ghosts


class Ghost; // Forward declaration of Ghost
class Map {
private:
    char grid[11][11] = {
        "##########",
        "#        #",
        "#  ##    #",
        "#        #",
        "#    ##  #",
        "#        #",
        "#  ##    #",
        "#        #",
        "#        #",
        "##########"
    };

public:
    Map() {} // Explicit constructor

    bool isValidMove(int x, int y) const { return grid[x][y] == ' '; }

    // FIX: Use forward-declared Ghost instead of including its header
    void render(const Pacman &player, const std::vector<Ghost*>& ghosts) const;
    std::string getRenderedMap(const Pacman& player, const std::vector<Ghost*>& ghosts) const;

};

#endif
