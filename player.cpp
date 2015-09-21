#include <iostream>
#include <SDL2/SDL.h>

//#include "gfx.h"
#include "general.h"
#include "input.h"
#include "player.h"
#include "entity.h"

Player::Player(SDL_Rect rectInput, SDL_Texture* textureInput/*,    Input up*/) {
	entityTexture = textureInput;
	entityRect = rectInput;
	//Gfx gfx;
}

SDL_Rect Player::movePlayer(/*SDL_Rect rectInput*/) {
	//rect = rectInput;
	//gfx.drawTexture(texture, rect);
	//General general;
	//general.checkCollision(s1Rect, e1Rect, 640, 480);
	//Input input;
	//Input down (SDLK_DOWN);
	//Input left (SDLK_LEFT);
	//Input right (SDLK_RIGHT);
	if (input.getKeyState(SDLK_UP) == true) {
		entityRect.y -= 1;
	}
	if (input.getKeyState(SDLK_DOWN) == true) {
		entityRect.y += 1;
	}
	if (input.getKeyState(SDLK_LEFT) == true) {
		entityRect.x -= 1;
	}
	if (input.getKeyState(SDLK_RIGHT) == true) {
		entityRect.x += 1;
	}
	player.drawEntity();
	return entityRect;
}
