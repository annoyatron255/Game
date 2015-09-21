#ifndef entity_h
#define entity_h
#include <iostream>
#include <SDL2/SDL.h>
#include "gfx.h"

class Entity {
	public:
		Entity();
		void drawEntity();
		SDL_Rect entityRect = {0, 0, 18, 24};
		SDL_Texture* entityTexture;
	private:

};
#endif
