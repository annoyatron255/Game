#include <stdio.h>
#include <SDL.h>

#include "Input.h"

Input::Input() {
	_speed = 3;
	_espeed = 2;
	_waitTime = 0;
	
	_done = false;
	_shift = false;
	
	_up = false;
	_down = false;
	_left = false;
	_right = false;
}

int Input::inputLoop() {
    SDL_Event event;
	
    while (SDL_PollEvent(&event)) {
        /** INPUT SETTINGS */
        switch (event.type) {
			case SDL_QUIT: // exit if the window is closed
				_done = true; // set done to true for exit
				break; // end caseclearscreen(red, green, blue, s1x, s1y, s1w, s1h);
				
			case SDL_KEYDOWN: // check for keypresses
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					_done = true;
				}
				
				if (event.key.keysym.sym == SDLK_UP) {
					_up = true;
				}
				
				if (event.key.keysym.sym == SDLK_DOWN) {
					_down = true;
				}
				
				if (event.key.keysym.sym == SDLK_LEFT) {
					_left = true;
				}
				
				if (event.key.keysym.sym == SDLK_RIGHT) {
					_right = true;
				}
				
				//if (event.key.keysym.sym == SDLK_s) {SDL_SaveBMP(screen, "screenshots/screenshot.bmp");}
				
				if (event.key.keysym.sym == SDLK_LSHIFT) {
					if (_waitTime <= 300) {
						_shift = true;
						_speed = 1;
					}
				}
				
				break; // end case
				
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_LSHIFT) {
					_speed = 3;
					_shift = false;
					_waitTime = 0;
				}
				
				if (event.key.keysym.sym == SDLK_UP) {
					_up = false;
				}
				
				if (event.key.keysym.sym == SDLK_DOWN) {
					_down = false;
				}
				
				if (event.key.keysym.sym == SDLK_LEFT) {
					_left = false;
				}
				
				if (event.key.keysym.sym == SDLK_RIGHT) {
					_right = false;
				}
				
				break; // end case
        } /** END INPUT SETTINGS */
    } // end of message processing
    return 0;
}

void Input::setSpeed(int speed) {
	_speed = speed;
}

int Input::getSpeed() {
	return _speed;
}

int Input::getESpeed() {
	return _espeed;
}

void Input::incrementWaitTime() {
	_waitTime++;
}

int Input::getWaitTime() {
	return _waitTime;
}

void Input::setGameDone() {
	_done = true;
}

bool Input::isGameDone() {
	return _done;
}

void Input::setShift(bool shift) {
	_shift = shift;
}

bool Input::isShiftPressed() {
	return _shift;
}

bool Input::getSpriteUp() {
	return _up;
}

bool Input::getSpriteDown() {
	return _down;
}

bool Input::getSpriteLeft() {
	return _left;
}

bool Input::getSpriteRight() {
	return _right;
}
