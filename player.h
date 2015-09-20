#ifndef player_h
#define player_h
#include <iostream>
//#include <stdlib.h>
#include <SDL2/SDL.h>
#include "input.h"


class Player {
	public:
		Player(SDL_Rect rectInput, SDL_Texture* textureInput/*, Input up*/);
		SDL_Rect movePlayer(/*SDL_Rect rectInput*/);
	private:
		SDL_Rect rect;
		SDL_Texture* texture;
		//Gfx gfx;
		//Input up (SDLK_UP);
		//SDL_Rect rectInput;
		//Input up;
		//Input up;
		//Input down; //(SDLK_DOWN);
		//Input left; //(SDLK_LEFT);
		//Input right;//(SDLK_RIGHT);
};
#endif
