#include "pacman.h"
#include "map.h"

void Pacman::move(int dx, int dy, const Map &gameMap) {
    if (gameMap.isValidMove(x + dx, y + dy)) {
        x += dx;
        y += dy;
        char tile = gameMap.getTile(x, y);
        eatPellet(tile);
        gameMap.eatPellet(x, y);
    }
    
    
}
