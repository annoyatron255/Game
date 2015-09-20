#include "general.h"
#include <iostream>
General::General() {

}

void General::checkCollision(SDL_Rect &s1Rect, SDL_Rect &e1Rect, int screenw, int screenh) {
	if (touching(s1Rect, e1Rect) == true ) {

	}

	if (s1Rect.y < 0) {
		s1Rect.y = 0;
	}

	if ((s1Rect.y + s1Rect.h) > screenh) {
		s1Rect.y = screenh - s1Rect.h;
	}

	if (s1Rect.x < 0) {
		s1Rect.x = 0;
	}

	if ((s1Rect.x + s1Rect.w) > screenw) {
		s1Rect.x = screenw - s1Rect.w;
	}
}

/*
   bool General::overlap(SDL_Rect rect1, SDL_Rect rect2) {
   if ((((abs(((rect2.x+(rect2.w/2))-(rect1.x+(rect1.w/2)))))<((rect1.w+rect2.w)/2))&((abs(((rect2.y+(rect2.h/2))-(rect1.y+(rect1.h/2)))))<((rect1.h+rect2.h)/2))) == 1) {
   return true;
   } else {
   return false;
   }
   }
 */

bool General::touching(SDL_Rect &rect1, SDL_Rect &rect2) {
	if ( (((abs(((rect2.x+(rect2.w/2))-(rect1.x+(rect1.w/2)))))<=((rect1.w+rect2.w)/2))&((abs(((rect2.y+(rect2.h/2))-(rect1.y+(rect1.h/2)))))<=((rect1.h+rect2.h)/2))) == 1) {
		return true;
	} else {
		return false;
	}
}
