#ifndef BONEGAM_H
#define BONEGAM_H

#include "Character.h"
#include "enermy.h"
#include "background.h"
#include "Sound.h"
#include <string>

class game : LTexture
{
public:
    struct input{
        enum type { QUIT, CLICK, NONE };
        type Type;
    };
    input UserInput;
    rocket Fapy;
    pile Pile;
    sound Sound;
    background Background;
    block FallingLeaf;
public:
    game();

    ~game();

    void takeInput();

    bool isQuit() {return quit; }

    void openFont( std::string );

    void display();

    bool initGraphic();

    void releaseGraphic();

    int getPileWidth() { return Pile.width();}

    int getPileHeight() {  return Pile.height();}

    void renderScore();

    bool isLost() {return lost;}

    void LoadText(std::string t);

    void renderText();

    void Restart();

    int getCountedFrame();

};

#endif // MYGAME_H
