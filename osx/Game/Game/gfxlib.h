/** gfxlib.h a simple easy lirary
 *  for controling gfx SDL functions.
 */

#ifndef gfxlib_h
#define gfxlib_h

#include "SDL.h"
#include <cstdio>
#include <string>

static SDL_Window* hardwin = 0;

static SDL_Renderer *renderer = 0;

static SDL_Texture *spriteTexture = 0;
static SDL_Texture *sleekSpriteTexture = 0;
static SDL_Texture *enemySpriteTexture = 0;

static SDL_Rect spriteRect;
static SDL_Rect sleekSpriteRect;
static SDL_Rect enemySpriteRect;

using namespace std;

void printErrorMessage(string component) {
	printf( "%s could not initialize! SDL_Error: %s\n", component.c_str(), SDL_GetError() );
}

void initgfx(int width, int height) {
    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printErrorMessage("SDL");
	}
	
	//Create window
	hardwin = SDL_CreateWindow( "SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
	if( hardwin == NULL )
	{
		printErrorMessage("Window");
	}
	
	renderer = SDL_CreateRenderer(hardwin, -1, SDL_RENDERER_PRESENTVSYNC);
	if ( renderer == NULL) {
		printErrorMessage("Renderer");
	}
}

void loadSpriteBitmap(const char *file) {
	// load bitmap
	SDL_Surface* Surf_Return = 0;
	
	Surf_Return = SDL_LoadBMP(file);
	if (Surf_Return == NULL) {
		printErrorMessage("Surf_Return");
	}
	
	SDL_SetColorKey(Surf_Return, SDL_TRUE, SDL_MapRGB(Surf_Return->format, 0, 0, 0));
	
	// convert surface to texture
	spriteTexture = SDL_CreateTextureFromSurface(renderer, Surf_Return);
	if (spriteTexture == NULL) {
		printErrorMessage("spriteTexture");
	}
	
	// free surface
	SDL_FreeSurface(Surf_Return);
}

void loadSleekSpriteBitmap(const char *file) {
	// load bitmap
	SDL_Surface* Surf_Return = 0;
	
	Surf_Return = SDL_LoadBMP(file);
	if (Surf_Return == NULL) {
		printErrorMessage("Surf_Return");
	}
	
	SDL_SetColorKey(Surf_Return, SDL_TRUE, SDL_MapRGB(Surf_Return->format, 0, 0, 0));
	
	// convert surface to texture
	sleekSpriteTexture = SDL_CreateTextureFromSurface(renderer, Surf_Return);
	if (sleekSpriteTexture == NULL) {
		printErrorMessage("spriteTexture");
	}
	
	// free surface
	SDL_FreeSurface(Surf_Return);
}

void loadEnemySpriteBitmap(const char *file) {
	// load bitmap
	SDL_Surface* Surf_Return = 0;
	
	Surf_Return = SDL_LoadBMP(file);
	if (Surf_Return == NULL) {
		printErrorMessage("Surf_Return");
	}
	
	SDL_SetColorKey(Surf_Return, SDL_TRUE, SDL_MapRGB(Surf_Return->format, 0, 0, 0));
	
	// convert surface to texture
	enemySpriteTexture = SDL_CreateTextureFromSurface(renderer, Surf_Return);
	if (enemySpriteTexture == NULL) {
		printErrorMessage("enemySpriteTexture");
	}
	
	// free surface
	SDL_FreeSurface(Surf_Return);
}

void update() {
	SDL_RenderPresent(renderer);
}

void displaySprite(int x, int y, int w, int h) {
    spriteRect.x = x;
    spriteRect.y = y;
	spriteRect.w = w;
	spriteRect.h = h;
	SDL_RenderCopy(renderer, spriteTexture, NULL, &spriteRect);
}

void displaySleekSprite(int x, int y, int w, int h) {
	sleekSpriteRect.x = x;
	sleekSpriteRect.y = y;
	sleekSpriteRect.w = w;
	sleekSpriteRect.h = h;
	SDL_RenderCopy(renderer, sleekSpriteTexture, NULL, &sleekSpriteRect);
}

void displayEnemySprite(int x, int y, int w, int h) {
	enemySpriteRect.x = x;
	enemySpriteRect.y = y;
	enemySpriteRect.w = w;
	enemySpriteRect.h = h;
	SDL_RenderCopy(renderer, enemySpriteTexture, NULL, &enemySpriteRect);
}

void clearscreen(int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 0);
	SDL_RenderClear(renderer);
}

int touching(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if ( (((abs(((x2+(w2/2))-(x1+(w1/2)))))<=((w1+w2)/2))&((abs(((y2+(h2/2))-(y1+(h1/2)))))<=((h1+h2)/2))) == 1) {
		return true;
	} else {
		return false;
	}
}

void closegfx() {
	SDL_DestroyTexture(spriteTexture);
	spriteTexture = 0;
	SDL_DestroyTexture(sleekSpriteTexture);
	sleekSpriteTexture = 0;
	SDL_DestroyTexture(enemySpriteTexture);
	enemySpriteTexture = 0;
	
	SDL_DestroyRenderer(renderer);
	renderer = 0;

	SDL_DestroyWindow(hardwin);
	hardwin = 0;
}

#endif
