#include <cstdio>
#include <SDL.h>
#include "general.h"

int overlap(SDL_Rect rect1, SDL_Rect rect2) {
    if ((((abs(((rect2.x+(rect2.w/2))-(rect1.x+(rect1.w/2)))))<((rect1.w+rect2.w)/2))&((abs(((rect2.y+(rect2.h/2))-(rect1.y+(rect1.h/2)))))<((rect1.h+rect2.h)/2))) == 1) {
        return true;
    } else {
        return false;
    }
}

int touching(SDL_Rect rect1, SDL_Rect rect2) {
    if ( (((abs(((rect2.x+(rect2.w/2))-(rect1.x+(rect1.w/2)))))<=((rect1.w+rect2.w)/2))&((abs(((rect2.y+(rect2.h/2))-(rect1.y+(rect1.h/2)))))<=((rect1.h+rect2.h)/2))) == 1) {
        return true;
    } else {
        return false;
    }
}
