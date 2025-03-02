#include "ghost.h"

Ghost::Ghost(int startX, int startY) : x(startX), y(startY) {}

void Ghost::move(int dx, int dy) {
    x += dx;
    y += dy;
}
