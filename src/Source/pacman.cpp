#include "pacman.h"
#include "map.h"

void Pacman::move(int dx, int dy, const Map &gameMap) {
    if (gameMap.isValidMove(x + dx, y + dy)) {
        x += dx;
        y += dy;
        char tile = gameMap.getTile(x, y);
        gameMap.eatPellet(x, y);
    }
}

void Pacman::eatPellet(char tile){
    if (tile == '.') score += 10; // Normal pellet
    else if (tile == '*') score += 50; // Power pellet
    // Add more conditions for other types of pellets if needed
}

void Pacman::addscore(int amount) {
    this->score += amount;
}