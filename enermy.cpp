#include "enermy.h"
#include "stdio.h"

std::vector<position> posPile;

bool pile::init()
{
    posPile.clear();
    double scale = 4;
    for (int i = 0; i < TOTAL_PILE; ++i)
    {
        position k;
        k.getPos( SCREEN_WIDTH + i * distance + 430, -(rand() % (2 * getHeight() + holeWidth - SCREEN_HEIGHT)));

        posPile.push_back(k);
    }
    if (isNULL())
    {
        if (Load( "img/pile.png", scale ))
        {
            return true;
        }
        printf("could not open img enemy");
    }
    return false;
}

void pile::Free()
{
    free();
    printf("pile success  !\n");
}

void pile::render()
{
    for (int i = 0; i < TOTAL_PILE; ++i)
    {
        if (posPile[i].x <= SCREEN_WIDTH && posPile[i].x > - getWidth())
            Render(posPile[i].x, posPile[i].y);
        Render(posPile[i].x, posPile[i].y + getHeight() + holeWidth, 180);
    }
}


void pile::update()
{
    if (!lost)
    {
        for (int j = 0; j < TOTAL_PILE; ++j)
        {
            if (posPile[j].x < - getWidth())
            {
                posPile[j].y = -(rand() % (2 * getHeight() + holeWidth - SCREEN_HEIGHT - 10));
                posPile[j].x = posPile[(j + TOTAL_PILE - 1) % TOTAL_PILE].x + distance;
            }
            else
                posPile[j].x -= 3;
        }
    }
}
