#ifndef input_h
#define input_h
#include <iostream>
//#include <stdlib.h>
#include <SDL2/SDL.h>


class Input {
	public:
		Input(SDL_Keycode keyInput);
		bool getKeyState();
		bool getQuit();
	protected:
		const Uint8 *state = SDL_GetKeyboardState(NULL);
	private:
		//bool getKeyDown(SDL_Keycode key);
		//bool getKeyUp(SDL_Keycode key);
		SDL_Keycode key;
		//const Uint8 *state = SDL_GetKeyboardState(NULL);
		bool keyState;// = false;

};
#endif



/*
   class Input {
   public:
   Input();
   bool _done;
   int inputLoop();

   void setSpeed(int speed);
   int getSpeed();
   int getESpeed();
   void incrementWaitTime();
   int getWaitTime();

   void setGameDone();
   bool isGameDone();
   void setShift(bool shift);
   bool isShiftPressed();

   bool getSpriteUp();
   bool getSpriteDown();
   bool getSpriteLeft();
   bool getSpriteRight();

   private:
   int _speed;
   int _espeed;
   int _waitTime;

//bool _done;
bool _shift;

bool _up;
bool _down;
bool _left;
bool _right;
};*/
