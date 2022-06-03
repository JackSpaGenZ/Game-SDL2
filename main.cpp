#include "boneGam.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    game g;
    srand(time(0));
    while(!g.isQuit())
    {
        if (g.isLost())
        {
            if (g.getCountedFrame() > 0) {
               // g.Sound.playChord();
            }
            std::string t = "Start by click or space key ";
            g.UserInput.Type = game::input::NONE;
            g.LoadText(t);
            while(g.isLost() && !g.isQuit())
            {
                g.takeInput();
                if (g.UserInput.Type == game::input::CLICK)
                {
                    if (!g.Sound.clickIconSpeaker())
                        g.Restart();
                    g.UserInput.Type = game::input::NONE;
                }
                g.Background.render();
                g.Pile.render();
                g.Fapy.render();
                g.renderText();
                g.renderScore();
              //  g.Sound.renderSpeaker();
                g.FallingLeaf.render();
                g.FallingLeaf.update();
                g.display();
               // g.Sound.playWhistlingBird();
            }
            g.Pile.init();
            g.Fapy.init();

        }
        else
        {
            g.takeInput();
            switch (g.UserInput.Type)
            {
            case game::input::CLICK:
                if (!g.Sound.clickIconSpeaker())
                {
                   // g.Sound.playSound();
                    g.Fapy.resetTime();
                }
                g.UserInput.Type = game::input::NONE;
                break;
            }
            g.Background.render();
            g.Pile.render();
            g.Fapy.render();
            g.renderScore();
            g.FallingLeaf.render();
           // g.Sound.renderSpeaker();
            g.display();
            g.Fapy.update(g.getPileWidth(), g.getPileHeight());
            g.Pile.update();
            g.Background.update();
            g.FallingLeaf.update();
           // g.Sound.playWhistlingBird();
        }
    }
    // success
    return 0;
}
