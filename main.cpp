/** Main.cpp controls lib.h for a simple
 *  Gfx example and Audio example.
 */

#include "Gfx.h" // general gfx lib I made for SDL
#include "Input.h"
#include "General.h"
#include "Sprite.h"

#define screenw 620
#define screenh 480

/** CHARS ARE DONE */
//int mousex; int mousey; int mouseon = 0;
//int red = 0; int green = 0; int blue = 0;

int main ( int argc, char** argv ) {
	SDL_Texture* s1Texture = NULL;
	SDL_Texture* s1TextureShift = NULL;
	SDL_Rect s1Rect = { 0, 0, 18, 24 }; //player x y w h
	SDL_Texture* e1Texture = NULL;
	SDL_Rect e1Rect = { 310, 240, 16, 16 }; //enemy x y w h
	
	Input *input = new Input();
	Sprite *sprite = new Sprite();
	Gfx *gfx = new Gfx();
	General *general = new General();
	
	float fps, frames, frameStartTime, frameEndTime;

    gfx->gfxinit(screenw, screenh); // open window with 620x480 res. with 8 bit color
	
	s1Texture = gfx->createTexture("gfx/s1.bmp", 0);
	s1TextureShift = gfx->createTexture("gfx/s1sneek.bmp", 1);
	e1Texture = gfx->createTexture("gfx/e1.bmp", 0);
	
    /* program main loop */
	while (!input->isGameDone()) {
		// get time when frame starts
		frameStartTime = SDL_GetTicks();
		
		input->inputLoop();
		sprite->move(input, s1Rect, e1Rect);
		general->checkCollision(input, s1Rect, e1Rect, screenw, screenh);

		gfx->clearScreen(100,0,0);

        if (!input->isShiftPressed()) {
            gfx->drawTexture(s1Texture, s1Rect);
        } else {
            gfx->drawTexture(s1TextureShift, s1Rect);
        }
		
        gfx->drawTexture(e1Texture, e1Rect);

        gfx->update();
		
		// get time at the end of frame after updating
		frameEndTime = SDL_GetTicks();
		// increment frames
		++frames;
	
		fps = frames / (SDL_GetTicks() / 1000);
		
		// Supposed ms per frame is 16.6666ms since 1000/60
		// if frame finishes early
		if ((frameEndTime - frameStartTime) < (1000/60)) {
			SDL_Delay((1000 / 60) - (frameEndTime - frameStartTime));
		}
    }
	
	delete sprite;
	delete input;
	delete general;

    gfx->close();
	
	delete gfx;

    return 0; // return success!
}

