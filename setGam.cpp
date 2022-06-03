#include "setGam.h"
#include <iostream>

bool LTexture::quit = false;
SDL_Window* LTexture::gWindow = NULL;
SDL_Renderer* LTexture::gRenderer = NULL;
TTF_Font* LTexture::Font = NULL;
SDL_Event LTexture::e;
int LTexture::countedFrame = -1;
int LTexture::score = 0;
bool LTexture::lost = true;

void LTexture::free()
{
	// xoa di neu Texture chua mat
	if( Texture != NULL )
	{
		SDL_DestroyTexture( Texture );
		Texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//mau RGB
	SDL_SetTextureColorMod( Texture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	// Tron
	SDL_SetTextureBlendMode( Texture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	// kieu alpha
	SDL_SetTextureAlphaMod( Texture, alpha );
}

int LTexture::getWidth()
{
	return tWidth;
}

int LTexture::getHeight()
{
	return tHeight;
}

void LTexture::Render(int x, int y, int angle, SDL_Rect* clip, SDL_RendererFlip flip)
{
	// cài đặt render các kích thước khoảng cách và màn hinh
		SDL_Rect Rec_Render = { x, y, tWidth, tHeight };

    if( clip != NULL )
	{
		Rec_Render.w = clip->w ;
		Rec_Render.h = clip->h ;
	}

	//render màn hình
    SDL_RenderCopyEx( gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip );
}

bool LTexture::Load( std::string path, double scale )
{
	//Free lại texture
	free();

	//Load ảnh
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//màu ảnh
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );

		//tạo texture từ pixel
        Texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( Texture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//nhận ảnh từ các chiều
			tWidth = (loadedSurface->w) * scale;
			tHeight = (loadedSurface->h) * scale;
		}

		//Free lại cái surface cũ
		SDL_FreeSurface( loadedSurface );
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Return 
	return Texture != NULL;

}

void LTexture::Load_Text( std::string text, int scale )
{
    free();
    SDL_Color Text_Color = { 255, 255, 255 };
    SDL_Surface* Text_Surface = TTF_RenderText_Solid( Font, text.c_str(), Text_Color );
    tWidth = Text_Surface->w * scale;
    tHeight = Text_Surface->h * scale;
    Texture = SDL_CreateTextureFromSurface( gRenderer, Text_Surface );
    SDL_FreeSurface( Text_Surface );
}

LTexture::LTexture()
{
    Texture = NULL;

}


bool LTexture::isNULL()
{
    if (Texture == NULL) return true;
    return false;
}

void LTexture::fixWidth(int newWidth)
{
    tWidth = newWidth;
}

void LTexture::fixHeight(int newHeight)
{
    tHeight = newHeight;
}

void position::getPos(const int x,const int y)
{
    this->x = x;
    this->y = y;
}

void position::getAngle(int newAngle)
{
    angle = newAngle;
}
