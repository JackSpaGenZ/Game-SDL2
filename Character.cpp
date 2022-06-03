#include "Character.h"
#include "background.h"
#include <stdio.h>
#include <iostream>

bool rocket::init()
{
    pos.getPos(50, SCREEN_HEIGHT / 2);
    ahead = 0;
    if (isNULL())
    {
        if ( Load( "img/rocket.png", scale ) )
        {
            angle = 0;
            time = -1;
            return true;
        }
        else
        {
            printf("could not load rocket.img\n");
            return false;
        }
    }
    return false;
}

void rocket::Free()
{
    free();
    std::cout << "rocket sucess !\n";
}

void rocket::render()
{
    Render(pos.x, pos.y, angle);
}

void rocket::update(int pileWidth, int pileHeight)
{
    if (!lost)
    {
        if (time == 0)
        {
            x0 = pos.y;
            angle = -20;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }
         // xử lý rơi tự do
        if (time >= 0)
        {
            pos.y = x0 + time * time * 0.1 - 5 * time;
            ++time;
        }
                 // chạm chướng ngoại vật 
        if ( (pos.x + getWidth() > posPile[ahead].x + 3) &&
                (pos.x + 5 < posPile[ahead].x + pileWidth) &&
                ( pos.y + 5 < posPile[ahead].y + pileHeight ||
                  pos.y  + getHeight()  > posPile[ahead].y + pileHeight + holeWidth ))
        {
            lost = true;
        }
         // nếu qua 1 cột thì tính 1 điểm 
        else if (pos.x > posPile[ahead].x + pileWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PILE;
            ++score;
        }
            // Quá màn hình 
        if ( pos.y - 8 > SCREEN_HEIGHT ||
                pos.y < - 8 )
        {
            lost = true;
        }
        
    }
}
