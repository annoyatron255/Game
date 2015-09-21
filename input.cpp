#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "input.h"

SDL_Keycode _key;
const Uint8 *state = SDL_GetKeyboardState(NULL);

namespace input {
	bool getKeyState(SDL_Keycode keyInput) {
		_key = keyInput;
		SDL_PumpEvents();
		return state[SDL_GetScancodeFromKey(_key)];
	}

	bool getQuit() {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return true; 
			} else {
				return false;
			}
		}
	}
}
