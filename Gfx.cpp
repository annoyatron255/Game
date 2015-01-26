/*
Gfx Functions
*/
#include <SDL2/SDL.h>
#include "Gfx.h"

Gfx::Gfx() {
	
}

int Gfx::gfxinit(int w,int h) {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    else {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}
        m_window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN );
        if(m_window == NULL) {
            printf("Window Error! SDL_Error: %s\n", SDL_GetError());
            return 1;
        } else {
            m_gRenderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_PRESENTVSYNC );
			if( m_gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				return 1;
			}
        }
    }
    return 0;
}

void Gfx::update() {
    SDL_RenderPresent( m_gRenderer );
}

void Gfx::clearScreen(int r, int b, int g) {
    SDL_SetRenderDrawColor( m_gRenderer, r, g, b, 0xFF );
    SDL_RenderClear( m_gRenderer );
}

void Gfx::drawRect(SDL_Rect rect, int r, int g, int b) {
    SDL_SetRenderDrawColor( m_gRenderer, r, g, b, 0xFF );
    SDL_RenderFillRect( m_gRenderer, &rect );
}

SDL_Texture* Gfx::createTexture(const char* file, int spriteCode) {
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
	
    surface = SDL_LoadBMP(file);
	
	if (spriteCode == 0) {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0, 0xFF));
	}
	
	// 1 for sneek sprite
	// different color key required
	if (spriteCode == 1) {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0, 0));
	}
	
    texture = SDL_CreateTextureFromSurface(m_gRenderer, surface);
	
    SDL_FreeSurface(surface);
    return texture;
}

void Gfx::drawTexture(SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(m_gRenderer, texture, NULL, &rect);
}

void Gfx::drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
    SDL_SetRenderDrawColor( m_gRenderer, r, g, b, 0xFF );
    SDL_RenderDrawLine(m_gRenderer, x1, y1, x2, y2);
}

void Gfx::close() {
	SDL_DestroyRenderer( m_gRenderer);
    SDL_DestroyWindow( m_window );
	
    SDL_Quit();
}
