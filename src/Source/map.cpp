#include "map.h"
#include "ghost.h"
#include <sstream>  // For string buffer

std::string Map::getRenderedMap(const Pacman &player, const std::vector<Ghost*>& ghosts) const {
    std::ostringstream buffer;  // Store the map as a string

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == player.getX() && j == player.getY()) {
                // buffer << 'P';  
                buffer << "\033[33mP\033[0m";// Pac-Man
            } else {
                bool ghostPrinted = false;
                for (const auto& ghost : ghosts) {
                    if (i == ghost->getX() && j == ghost->getY()) {
                        // buffer << 'G';
                        buffer << ghost->getSymbol();  // Ghost
                        ghostPrinted = true;
                        break;  // Skip other ghosts at this position
                    }
                }
                if (!ghostPrinted) {
                    buffer << grid[i][j];  // Render map
                }
            }
        }
        buffer << '\n';  // New line for each row
    }
    return buffer.str();  // Return map as a string
}


