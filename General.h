#ifndef General_h
#define General_h

#include <SDL_rect.h>

#include "Input.h"

class General {
	public:
		General();
	
		//int overlap(SDL_Rect rect1, SDL_Rect rect2);
		void checkCollision(Input *input, SDL_Rect &s1Rect, SDL_Rect &e1Rect, int screenw, int screenh);
		int touching(SDL_Rect &rect1, SDL_Rect &rect2);
	
	private:
};

#endif
