#ifndef entity_h
#define entity_h
#include <iostream>
#include <SDL2/SDL.h>
#include "gfx.h"

class Entity {
	public:
		Entity(/*SDL_Rect rectInput, SDL_Texture* textureInput*/);
		void drawEntity();
	protected:
		SDL_Rect entityRect = {0, 0, 18, 24};
		SDL_Texture* entityTexture;
	private:
		

};
#endif
