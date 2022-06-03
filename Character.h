#ifndef CHARACTER_H
#define CHARACTER_H

#include "setGam.h"
#include "enermy.h"

class rocket : LTexture
{
private:
    int angle, time, x0;
    position pos;
    const double scale = 1;
    int ahead = 0;
public:
    bool init();

    void render();

    void Free();

    void resetTime() { time = 0;}

    void update(int pileWidth, int pileHeight);
};

#endif // CHARACTER_H
