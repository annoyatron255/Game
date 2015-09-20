#ifndef General_h
#define General_h
#include <iostream>
#include <SDL2/SDL_rect.h>

#include "input.h"

class General {
	public:
		General();

		//bool overlap(SDL_Rect rect1, SDL_Rect rect2);
		void checkCollision(SDL_Rect &s1Rect, SDL_Rect &e1Rect, int screenw, int screenh);
		bool touching(SDL_Rect &rect1, SDL_Rect &rect2);

	private:
};

#endif
