#include "Sound.h"
#include <stdio.h>
#include <iostream>
#include <string>

/*bool sound::init()
{
    std::string MUS_Path = "sound/Stardew Valley OST - Mines (Cloth).mp3";
    std::string flap_Path = "sound/wing_flap.mp3";
    std::string chord_Path = "sound/jazzy chords.mp3";
    std::string speakerIMG = "img/speaker.png";
    std::string BirdWhistling_Path = "sound/bird whistling.mp3";
    bool success = true;
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

        Music = Mix_LoadMUS( MUS_Path.c_str() );
        if( Music == NULL )
        {
            printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        Flapping = Mix_LoadWAV( flap_Path.c_str() );
        if ( Flapping == NULL )
        {
            printf( "Failed to load sound! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        Chord = Mix_LoadWAV( chord_Path.c_str() );
        if (Chord == NULL)
        {
            printf( "Failed to load chord! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

        // load speaker image
        if (!Load(speakerIMG))
        {
            return false;
        }
        BirdWhistling = Mix_LoadWAV( BirdWhistling_Path.c_str() );
        if (BirdWhistling == NULL)
        {
            printf( "Failed to load bird whistling! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

        Mute.x = 0; Mute.y = 0; Mute.w = getWidth(); Mute.h = getHeight() / 2;
        Active.x = 0; Active.y = getHeight() / 2; Active.w = getWidth(); Active.h = getHeight() / 2;
        playing = true;
        playMusic();
        std::cout << "Stardew Valley OST - Mines (Cloth)" << std::endl;
    }
    return success;
}

void sound::Free()
{
    // free speaker image
    free();

    // free sound effect
    Mix_FreeChunk( Flapping );
    Flapping = NULL;
    Mix_FreeChunk( Chord );
    Chord = NULL;
    Mix_FreeChunk(BirdWhistling);
    BirdWhistling = NULL;

    // free music
    Mix_FreeMusic( Music );
    Music = NULL;

    Mix_Quit();

    printf("Free sound!\n");
}

void sound::playSound()
{
    if (playing)
    {
        Mix_PlayChannel( -1, Flapping, 0 );
    }
}

void sound::playMusic()
{
    if ( Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic( Music, -1 );
    }
    else
    {
        if ( Mix_PausedMusic() )
        {
            Mix_ResumeMusic();
        }
        else
        {
            Mix_PauseMusic();
        }
    }
}

void sound::playChord()
{
    if (playing)
    {
        Mix_PlayChannel( -1, Chord, 0 );
    }
}

void sound::renderSpeaker()
{
    if (playing)
    {
        Render( SCREEN_WIDTH - getWidth(), 0, 0, &Active );
    }
    else
    {
        Render( SCREEN_WIDTH - getWidth(), 0, 0, &Mute );
    }
}
*/
bool sound::clickIconSpeaker()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > SCREEN_WIDTH - getWidth() &&
        x < SCREEN_WIDTH &&
        y > 0 &&
        y < getHeight() / 2)
    {
        playing = !playing;
        //playMusic();
        return true;
    }
    return false;
}

/* void sound::playWhistlingBird()
{
    if ((countedFrame & 511 ) == 0)
    {
        if (playing) Mix_PlayChannel( -1, BirdWhistling, 0 );
    }
}


*/