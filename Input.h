#ifndef input_h
#define input_h

#include <stdlib.h>

class Input {
	public:
		Input();
	
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
	
		bool _done;
		bool _shift;
		
		bool _up;
		bool _down;
		bool _left;
		bool _right;
};

#endif