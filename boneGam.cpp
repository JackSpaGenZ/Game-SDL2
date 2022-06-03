#include "boneGam.h"
#include <iostream>
#include "setGam.h"


void game::takeInput()
{
    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            UserInput.Type = input::QUIT;
            quit = true;
        }
        else if ( e.type == SDL_MOUSEBUTTONDOWN || e.key.keysym.sym == SDLK_SPACE )
        {
            UserInput.Type = input::CLICK;
        }
    }
}

void game::openFont( std::string )
{
    Font = TTF_OpenFont( "vgasys.fon", Font_Size );
    if( Font == NULL )
	{
		printf( "Failed to load vgasys font! SDL_ttf Error: %s\n", TTF_GetError() );
	}
}

game::game()
{
    initGraphic();
    Fapy.init();
    Pile.init();
    FallingLeaf.init();
    Background.init();
   // Sound.init();
    openFont("vgasys.fon");
}

game::~game()
{

    Fapy.Free();

    Pile.Free();

    Background.Free();

    FallingLeaf.Free();

    //Sound.Free();

    free();

    releaseGraphic();
}

void game::releaseGraphic()
{
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_DestroyRenderer( gRenderer );
    gRenderer = NULL;
    TTF_CloseFont( Font );
    Font = NULL;

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

bool game::initGraphic()
{
    //Initialization flag
	bool success = true;

	countedFrame = -1;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

                //Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


void game::display()
{

    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
    ++countedFrame;
}

std::string convert_int_to_string(int num)
{
    std::string k;
    if (num == 0)
        return "0";
    while(num > 0)
    {
        std::string m;
        m = (char)(num % 10) + 48;
        k = m + k;
        num /= 10;
    }
    return k;
}

void game::renderScore()
{
    std::string s = convert_int_to_string(score);
    LTexture text;
    text.Load_Text(s,Font_Size + 3 );
    SDL_SetTextureAlphaMod(text.Texture, 200);
    text.Render((SCREEN_WIDTH - text.getWidth()) / 2, 70);
    text.free();
}

void game::LoadText(std::string t)
{
    if ( isNULL() ) {
        Load_Text(t, Font_Size);
    }
}

void game::renderText()
{
    Render((SCREEN_WIDTH - getWidth()) / 2, 150);
}

void game::Restart()
{
    lost = false;
    score = 0;
    Fapy.resetTime();
}

int game::getCountedFrame()
{
    return countedFrame;
}
