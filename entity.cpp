#include <iostream>
#include <SDL2/SDL.h>
#include "entity.h"
#include "gfx.h"

Entity::Entity() {

}

void Entity::drawEntity() {
	gfx::drawTexture(entityTexture, entityRect);
}
