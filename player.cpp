#include <iostream>
#include <SDL2/SDL.h>

//#include "gfx.h"
#include "general.h"
#include "input.h"
#include "player.h"

Player::Player(SDL_Rect rectInput, SDL_Texture* textureInput/*, Input up*/) {
	texture = textureInput;
	rect = rectInput;
	//Gfx gfx;
}

SDL_Rect Player::movePlayer(/*SDL_Rect rectInput*/) {
	//rect = rectInput;
	//gfx.drawTexture(texture, rect);
	//General general;
	//general.checkCollision(s1Rect, e1Rect, 640, 480);
	Input up (SDLK_UP);
	Input down (SDLK_DOWN);
	Input left (SDLK_LEFT);
	Input right (SDLK_RIGHT);
	if (up.getKeyState() == true) {
		rect.y -= 1;
	}
	if (down.getKeyState() == true) {
		rect.y += 1;
	}
	if (left.getKeyState() == true) {
		rect.x -= 1;
	}
	if (right.getKeyState() == true) {
		rect.x += 1;
	}
	return rect;
}
