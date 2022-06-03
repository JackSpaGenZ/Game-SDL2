#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "setGam.h"
#include <vector>

class background : LTexture
{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    position pos;
    double scale;
};

class block : LTexture
{
private:
    std::vector<position> pos;
    
public:

    bool init();

    void Free();

    void update();

    void render();
};

#endif // BACKGROUND_H
