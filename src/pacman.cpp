#include "pacman.h"
#include "map.h" // Include Map here instead of pacman.h

Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

void Pacman::move(int dx, int dy, Map &gameMap) {
    if (gameMap.isValidMove(x + dx, y + dy)) {
        x += dx;
        y += dy;
    }
}
