#include "background.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>



bool background::init()
{
    pos.getPos(0, 0);
    scale = 1;
    std::string path = "img/background2.png";
    if (isNULL())
    {
        if ( Load( path.c_str(), scale ) )
        {
            int height = getHeight();
            scale = (double)SCREEN_HEIGHT / height;
            fixWidth(scale * getWidth());
            fixHeight(scale * getHeight());
            return true;
        }
        else
        {
            printf("could not load %s\n", &path);
            return false;
        }
    }
    return false;
}

void background::Free()
{
    free();
    std::cout << "background succes !\n";
}

void background::render()
{    // cuộn 
    if (pos.x > -getWidth() + SCREEN_WIDTH)
    {
        Render(pos.x, pos.y);
    }
    else if (pos.x >= -getWidth() && pos.x <= -getWidth() + SCREEN_WIDTH)
    {
        Render(pos.x, pos.y);
        Render(pos.x + getWidth(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else if (pos.x > - 2 * getWidth() + SCREEN_HEIGHT)
    {
        Render(pos.x + getWidth(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else if (pos.x > - 2 * getWidth() && pos.x <= - 2 * getWidth() + SCREEN_HEIGHT)
    {
        Render(pos.x + getWidth(), pos.y, 0, NULL, SDL_FLIP_HORIZONTAL);
        Render(pos.x + 2 * getWidth(), pos.y);
    }
    else
    {
        pos.getPos(0, 0);
        Render(pos.x, pos.y);
    }
}

void background::update()
{
    --pos.x;
}

bool block::init()
{
    std::string path = "img/block.png";
    if (isNULL())
    {
        if ( Load( path.c_str() ) )
        {

            return true;
        }
        else
        {
            printf("could not load %s\n", &path);
            return false;
        }
    }
    return false;
}

void block::Free()
{
    free();
    printf("block success  !\n");
}

void block::update()
{  
    if ( pos.size() < 10 && (countedFrame & 63) == 0 )
    {
        position tem;
        int x = rand() % (SCREEN_WIDTH) + 200;
        int y;
        if (x > SCREEN_WIDTH) {
            y = rand() % (SCREEN_HEIGHT << 1) + 30;
        }
        else y = -getHeight();
        tem.getPos( x,y );
        tem.getAngle(0);
        tem.state = 0;
        pos.push_back(tem);
    }
    for (int i = 0; i < pos.size(); ++i)
    {
        if (!lost)
        {
            pos[i].x -= 2;
            pos[i].y += 1;
            if (pos[i].angle > 75)
            {
                pos[i].state = 0;
            }
            if (pos[i].angle < -15)
            {
                pos[i].state = 1;
            }
            switch(pos[i].state)
            {
            case 1:
                pos[i].angle += 1;
                break;
            case 0:
                pos[i].angle -= 1;
                break;
            }
        }
        else
        {
            if ((countedFrame & 3) == 0)
                pos[i].x -= 1;

            pos[i].y += 1;
            if (pos[i].angle > 75)
            {
                pos[i].state = 0;
            }
            if (pos[i].angle < -15)
            {
                pos[i].state = 1;
            }
            switch(pos[i].state)
            {
            case 1:
                pos[i].angle += 1;
                break;
            case 0:
                pos[i].angle -= 1;
                break;
            }
        }
        if (pos[i].y > SCREEN_HEIGHT || pos[i].x < -getWidth())
        {
            pos.erase(pos.begin() + i);
        }
    }
}

void block::render()
{
    for (int i = 0; i < pos.size(); ++i)
    {
        if (pos[i].x < SCREEN_WIDTH)
        {
            if (pos[i].state == 0) {
                Render(pos[i].x, pos[i].y, pos[i].angle );
            }
            else Render(pos[i].x, pos[i].y, pos[i].angle);
        }
    }
}
