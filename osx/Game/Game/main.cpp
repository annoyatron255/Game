/** Main.cpp controls lib.h for a simple
 *  Gfx example and Audio example.
 */

#ifdef __cplusplus  // choose what c++ io lib to use
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "SDL.h" // include SDL lib for gfx + sound install SDL in compliers include directory!
#include "gfxlib.h" // general gfx lib I made for SDL

#define screenw 640
#define screenh 480

SDL_Event event;

// sprite speed
int speed = 3;
// enemy speed
int espeed = 2;

float framesCount = 0;
float actualFPS;
const float FPS = 60;
const Uint32 SECONDS_PER_FRAME = 1000.0f/FPS;
Uint32 frameStartTime = 0;
Uint32 frameEndTime = 0;

// bullets
int bulletw = 1, bulleth = 1;

// sprite
int s1w = 16, s1h = 16, s1x = 0, s1y = 0;
// enemy
int e1w = 16, e1h = 16, e1x = 310, e1y = 240;

// mouse
int mousex, mousey, mouseon = 0;
const int RED = 100, GREEN = 0, BLUE = 0;

int wait2 = 0;

// controls
bool left = false, right = false, up = false, down = false;
bool shift = false;

using namespace std;

int main ( int argc, char** argv ) {
    initgfx(screenw, screenh); // open window with 620x480 res. with 8 bit color
	
    bool done = false; // make bool done for while statment
	
	loadSpriteBitmap("gfx/s1.bmp");
	loadSleekSpriteBitmap("gfx/s1sneek.bmp");
	loadEnemySpriteBitmap("gfx/e1.bmp");
	
	/* program main loop */
	while (!done) {
		frameStartTime = SDL_GetTicks();
	
		// check for collision
		done = touching(s1x, s1y, s1w, s1h, e1x, e1y, e1w, e1h);
	
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
				case SDL_QUIT:
					done = true;
					break; // end case clearscreen(red, green, blue, s1x, s1y, s1w, s1h);
					
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						done = true;
					}
					
					if (event.key.keysym.sym == SDLK_UP) {
						up = true;
					}
					
					if (event.key.keysym.sym == SDLK_DOWN) {
						down = true;
					}
					
					if (event.key.keysym.sym == SDLK_LEFT) {
						left = true;
					}
					
					if (event.key.keysym.sym == SDLK_RIGHT) {
						right = true;
					}
					
					if (event.key.keysym.sym == SDLK_s) {
						// sorry, I dont know how to screenshot with textures
					}
					
					if (event.key.keysym.sym == SDLK_LSHIFT) {
						if (wait2 <= 300) {
							// set shift to true and slow sprite down
							shift = true;
							speed = 1;
						}
					}
					
					break;
					
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_LSHIFT) {
						// set sprite speed to normal and wait2 to 0
						speed = 3;
						shift = false;
						wait2 = 0;
					}
					
					if (event.key.keysym.sym == SDLK_UP) {
						up = false;
					}
					
					if (event.key.keysym.sym == SDLK_DOWN) {
						down = false;
					}
					
					if (event.key.keysym.sym == SDLK_LEFT) {
						left = false;
					}
					
					if (event.key.keysym.sym == SDLK_RIGHT) {
						right = false;
					}
					
					break;
					
					// is this what you meant by mouse support?
					// the sprite moves with the mouse
				case SDL_MOUSEMOTION:
					s1x = event.motion.x;
					s1y = event.motion.y;
					break;
            }
        }
		
		// player holds shift
        if (shift == true) {
			// increment wait2
			wait2++;
		}
		
        if (wait2 >= 300) {
			shift = false;
			speed = 3;
		}
		
        if (up == true) {
			s1y -= speed;
		}
		
        if (down == true) {
			s1y += speed;
		}
		
        if (left == true) {
			s1x -= speed;
		}
		
        if (right == true) {
			s1x += speed;
		}
		
        if ((s1x + s1w) > screenw) {
			s1x = (screenw - s1w);
		}
		
        if ((s1y + s1h) > screenh) {
			s1y = (screenh - s1h);
		}
		
        if (s1x < 0) {
			s1x = 0;
		}
		
        if (s1y < 0) {
			s1y = 0;
		}
		
        if (shift == false) {
			// if sprite is left to enemy
            if ((s1x - e1x) < 0) {
				// enemy x position minus speed
				// enemy goes towards sprite
				e1x -= espeed;
			}
			
            if ((s1x - e1x) > 0) {
				e1x += espeed;
			}
			
            if ((s1y - e1y) < 0) {
				e1y -= espeed;
			}
			
            if ((s1y - e1y) > 0) {
				e1y += espeed;
			}
		}
		
		// render
		clearscreen(RED, GREEN, BLUE); // clear the whole screen
		
		if (shift == false) {
			displaySprite(s1x, s1y, s1w, s1h);
		} else {
			displaySleekSprite(s1x, s1y, s1w, s1h);
		}
		
		displayEnemySprite(e1x, e1y, e1w, e1h);
		
		// update
		update();
		
		frameEndTime = SDL_GetTicks();
		
		++framesCount;
		
		actualFPS = framesCount / (SDL_GetTicks() / 1000);
		
		// keeps framerate capped at 60
		if (SECONDS_PER_FRAME < (frameEndTime - frameStartTime)) {
			SDL_Delay((frameEndTime - frameStartTime) - SECONDS_PER_FRAME);
		}
		printf("FPS: %lf\n", actualFPS);
    }
	
    closegfx(); // free loaded textures
	
    printf("Exited cleanly\n"); // all is well (i think...)
    return 0; // return success!
}
