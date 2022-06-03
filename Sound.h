#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <string>
#include "setGam.h"

class sound : LTexture
{
public:

    bool playing;

    bool init();

    void Free();

    void playSound();

    void playMusic();

    void playChord();

    void renderSpeaker();

    bool clickIconSpeaker();

    void playWhistlingBird();

private:

    Mix_Music* Music = NULL;
    Mix_Chunk* Flapping = NULL;
    Mix_Chunk* BirdWhistling = NULL;
    Mix_Chunk* Chord = NULL;
    SDL_Rect Mute ;
    SDL_Rect Active ;

};


#endif // SOUND_H
