//
//  Sprite.h
//  Game
//
//  Created by Muhd Mirza on 27/12/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

//#ifndef __Game__Sprite__
//#define __Game__Sprite__
#ifndef Sprite_h
#define Sprite_h


#include <SDL2/SDL.h>

#include "input.h"

class Sprite {
	public:
		Sprite();

		void move(Input input, SDL_Rect &s1Rect, SDL_Rect &e1Rect);

	private:

};

#endif /* defined(__Game__Sprite__) */
