/** Main.cpp controls lib.h for a simple
 *  Gfx example and Audio example.
 */

#include "gfx.h" // general gfx lib I made for SDL
#include "input.h"
#include "general.h"
#include "player.h"
#include <iostream>
#define screenw 640
#define screenh 480

Uint8 screenR = 0;
Uint8 screenG = 0;
Uint8 screenB = 0;

Uint8 screenRout = 255;
Uint8 screenGout = 255;
Uint8 screenBout = 0;

/** CHARS ARE DONE */
//int mousex; int mousey; int mouseon = 0;
//int red = 0; int green = 0; int blue = 0;

int main ( int argc, char** argv ) {
	//Load Classes
	//Gfx gfx;
	//Gfx Config
	gfx::gfxinit(screenw, screenh); // open window with 640x480 res. 
	SDL_Texture* s1Texture = gfx::createTexture("gfx/s1.bmp");
	SDL_Texture* s1TextureShift = gfx::createTexture("gfx/s1sneek.bmp");
	SDL_Texture* e1Texture = gfx::createTexture("gfx/e1.bmp");
	//Gfx Rects
	SDL_Rect e1Rect = { 0,0,/*310, 240,*/ 16, 16 }; //enemy x y w h
	SDL_Rect s1Rect = { 40, 40, 18, 24 }; //player x y w h
	//General
	//General general;
	//Input
	//Input input;
	//Input up (SDLK_UP);

	//Dependent Classes
	//Player Class
	Player s1(s1Rect, s1Texture);//, up);

	//float fps, frames, frameStartTime, frameEndTime;

	/* program main loop */
	while (!(input::getKeyState(SDLK_ESCAPE) || input::getQuit())) {
		// get time when frame starts
		//frameStartTime = SDL_GetTicks();

		//general.checkCollision(s1Rect, e1Rect, screenw, screenh);

		if (screenR > screenRout) {screenR--;} else
			if (screenR < screenRout) {screenR++;}
		if (screenG > screenGout) {screenG--;} else
			if (screenG < screenGout) {screenG++;}
		if (screenB > screenBout) {screenB--;} else
			if (screenB < screenBout) {screenB++;}

		gfx::clearScreen(screenR, screenG, screenB);
		s1.movePlayer(/*s1Rect*/);
		//if (!shift.getKeyState()) {
		//s1Rect.x += 1;
		//gfx.drawTexture(s1Texture, s1Rect);
		//gfx.drawRect(s1Rect, 0, 0, 100);
		//} else {
		//gfx.drawTexture(s1TextureShift, s1Rect);
		//}

		gfx::drawTexture(e1Texture, e1Rect);

		gfx::update();
		/* Using Vsync -- no need
		// get time at the end of frame after updating
		frameEndTime = SDL_GetTicks();
		// increment frames
		++frames;

		fps = frames / (SDL_GetTicks() / 1000);

		if ((1000 / 60) < (frameEndTime - frameStartTime)) {
		SDL_Delay((frameEndTime - frameStartTime) - (1000 / 60));
		}*/
	}

	gfx::close();

	return 0; // return success!
}
