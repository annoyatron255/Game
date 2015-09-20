//
//  Sprite.cpp
//  Game
//
//  Created by Muhd Mirza on 27/12/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "sprite.h"

Sprite::Sprite() {

}


void Sprite::move(Input input, SDL_Rect &s1Rect, SDL_Rect &e1Rect) {
	/*if (input.isShiftPressed()) {
		input.incrementWaitTime();
	}

	if (input.getWaitTime() >= 300) {
		input.setShift(false);
		input.setSpeed(3);
	}

	if (input.getSpriteUp()) {
		s1Rect.y -= input.getSpeed();
	}

	if (input.getSpriteDown()) {
		s1Rect.y += input.getSpeed();
	}

	if (input.getSpriteLeft()) {
		s1Rect.x -= input.getSpeed();
	}

	if (input.getSpriteRight()) {
		s1Rect.x += input.getSpeed();
	}

	if (!input.isShiftPressed()) {
		if ((s1Rect.x - e1Rect.x) < 0) {
			e1Rect.x -= input.getESpeed();
		}

		if ((s1Rect.x - e1Rect.x) > 0) {
			e1Rect.x += input.getESpeed();
		}

		if ((s1Rect.y - e1Rect.y) < 0) {
			e1Rect.y -= input.getESpeed();
		}

		if ((s1Rect.y - e1Rect.y) > 0) {
			e1Rect.y += input.getESpeed();
		}
	}*/
}
