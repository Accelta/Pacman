#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "pacman.h" // Already includes Pacman
#include <vector> // Include vector for multiple ghosts


class Ghost; // Forward declaration of Ghost
class Map {
private:
char grid[20][20] = {
    "###################",
    "#........#........#",
    "#.####...#...####.#",
    "#.*............*..#",
    "#...##.......##...#",
    "#.................#",
    "#.##...## ##...##.#",
    "#......#.B.#......#",
    "#.##...#####...##.#",
    "#.....*.....*.....#",
    "#.................#",
    "#...##.......##...#",
    "#.*............*..#",
    "#.####...#...####.#",
    "#........#........#",
    "#...*.....*.....*.#",
    "#.##.........##...#",
    "#.........*.......#",
    "#.................#",
    "###################"
};

public:
    Map() {} // Explicit constructor

    bool isValidMove(int x, int y) const { return grid[x][y] == ' '|| grid[x][y] == '.' || grid[x][y] == '*'; }
    char getTile(int x, int y) const { return grid[x][y]; }
    void eatPellet(int x, int y) const {
        if (grid[x][y] == '.' || grid[x][y] == '*') {
            const_cast<Map*>(this)->grid[x][y] = ' '; // Remove the pellet
        }
    }
    
    std::string getRenderedMap(const Pacman& player, const std::vector<Ghost*>& ghosts) const;

};

#endif
