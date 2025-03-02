#ifndef GHOST_H
#define GHOST_H

class Ghost {
public:
    int x, y;
    
    Ghost(int startX, int startY);
    void move(int dx, int dy);
};

#endif
