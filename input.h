#ifndef input_h
#define input_h
#include <iostream>
#include <SDL2/SDL.h>

namespace input {
	bool getKeyState(SDL_Keycode keyInput);
	bool getQuit();
}
#endif
