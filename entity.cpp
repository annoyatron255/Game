#include <iostream>
#include <SDL2/SDL.h>
#include "entity.h"
#include "gfx.h"

Entity::Entity(/*SDL_Rect rectInput, SDL_Texture* textureInput*/) {
	//entityRect = rectInput;
	//entityTexture = textureInput;
}

void Entity::drawEntity() {
	//gfx::drawTexture(entityTexture, entityRect);
	gfx::drawTexture((gfx::createTexture("./gfx/s1.bmp", 0)), entityRect);
}
