#include <iostream>
#include <SDL2/SDL.h>

//#include "gfx.h"
#include "general.h"
#include "input.h"
#include "player.h"
#include "entity.h"

Player::Player(SDL_Rect rectInput, SDL_Texture* textureInput) {
	player.entityTexture = textureInput;
	player.entityRect = rectInput;
}

void Player::movePlayer() {
	if (input::getKeyState(SDLK_UP) == true) {
		player.entityRect.y -= 1;
	}
	if (input::getKeyState(SDLK_DOWN) == true) {
		player.entityRect.y += 1;
	}
	if (input::getKeyState(SDLK_LEFT) == true) {
		player.entityRect.x -= 1;
	}
	if (input::getKeyState(SDLK_RIGHT) == true) {
		player.entityRect.x += 1;
	}
	player.drawEntity();
}
