/** Main.cpp controls lib.h for a simple
 *  Gfx example and Audio example.
 */

#include <stdlib.h>
#include <SDL.h> // include SDL lib for gfx + sound install SDL in compliers include directory!
#include "gfx.h" // general gfx lib I made for SDL
#include "input.h"
#include "general.h"

int speed = 3; int espeed = 2;
bool done = false;
#define screenx 620
#define screeny 480
/**CHARS ARE MADE*/
SDL_Texture* s1Texture = NULL;
SDL_Texture* s1TextureShift = NULL;
SDL_Rect s1Rect = { 0, 0, 18, 24 }; //player x y w h
SDL_Texture* e1Texture = NULL;
SDL_Rect e1Rect = { 310, 240, 16, 16 }; //enemy x y w h
/** CHARS ARE DONE */
//int mousex; int mousey; int mouseon = 0;
//int red = 0; int green = 0; int blue = 0;
int wait = 0; //int wait2 = 0;
bool left = 0; bool right = 0; bool up = 0; bool down = 0;
bool shift = 0;

int main ( int argc, char** argv ) { // init for SDL
    /** INIT. ALL LIBRARYS */
    gfxinit(screenx, screeny); // open window with 620x480 res. with 8 bit color
    s1Texture = createTexture("gfx/s1.bmp");
    s1TextureShift = createTexture("gfx/s1sneek.bmp");
    e1Texture = createTexture("gfx/e1.bmp");
    clearScreen(0,0,0);
    /** INIT. ALL LIBRARYS END */
    /* program main loop */
    while (!done) { // loop until done = true
        clearScreen(0,0,0);
        if (overlap(s1Rect, e1Rect) == true) {
            done = true;
        }
        inputLoop();
        /** LOGIC STARTS HERE */
        if (shift == 1) {wait++;}
        if (wait >= 300) {shift = 0; speed = 300;}
        if (up == 1) {s1Rect.y -= speed;}
        if (down == 1) {s1Rect.y += speed;}
        if (left == 1) {s1Rect.x -= speed;}
        if (right == 1) {s1Rect.x += speed;}
        if ((s1Rect.x + s1Rect.w) > screenx) {s1Rect.x = (screenx - s1Rect.w);}
        if ((s1Rect.y + s1Rect.h) > screeny) {s1Rect.y = (screeny - s1Rect.h);}
        if (s1Rect.x < 0) {s1Rect.x = 0;}
        if (s1Rect.y < 0) {s1Rect.y = 0;}
        if (shift == 0) {
            if ((s1Rect.x - e1Rect.x) < 0) {e1Rect.x -= espeed;}
            if ((s1Rect.x - e1Rect.x) > 0) {e1Rect.x += espeed;}
            if ((s1Rect.y - e1Rect.y) < 0) {e1Rect.y -= espeed;}
            if ((s1Rect.y - e1Rect.y) > 0) {e1Rect.y += espeed;}
        }
        /** LOGIC ENDS HERE */
        /** DRAWING STARTS HERE */
        if (shift == 0) {
            drawTexture(s1Texture, s1Rect);
        } else {
            drawTexture(s1TextureShift, s1Rect);
        }
        drawTexture(e1Texture, e1Rect);
        /** DRAWING ENDS HERE */
        update(); // finally, update the screen to make changes
    } // end main loop
    /** CLEAN UP STARTS */
    close(); // free loaded bitmap
    /** CLEAN UP ENDS */
    return 0; // return success!
}

