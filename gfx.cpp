/*
Gfx Functions
*/
#include <stdio.h>
#include <SDL.h>
#include "gfx.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* gRenderer = NULL;

int gfxinit(int x,int y) {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    else {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}
        window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN );
        if(window == NULL) {
            printf("Window Error! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
        else {
            screenSurface = SDL_GetWindowSurface( window );
            gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				return 1;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			}
        }
    }
    return 0;
}

int update() {
    SDL_RenderPresent( gRenderer );
    return 0;
}

int clearScreen(int r, int b, int g) {
    SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );
    SDL_RenderClear( gRenderer );
    return 0;
}

int drawRect(SDL_Rect rect, int r, int g, int b) {
    SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );
    SDL_RenderFillRect( gRenderer, &rect );
    return 0;
}

SDL_Texture* createTexture(const char* file) {
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    surface = SDL_LoadBMP(file);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0, 0xFF));
    texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

int drawTexture(SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(gRenderer, texture, NULL, &rect);
    return 0;
}

int drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
    SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );
    SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

int close() {
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
