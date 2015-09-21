#ifndef player_h
#define player_h
#include <iostream>
//#include <stdlib.h>
#include <SDL2/SDL.h>
#include "input.h"
#include "entity.h"

class Player {
	public:
		Player(SDL_Rect rectInput, SDL_Texture* textureInput);
		void movePlayer();
	private:
		Entity player;
};
#endif
