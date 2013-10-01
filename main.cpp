/** Main.cpp controls lib.h for a simple
 *  Gfx example and Audio example.
 */

// The todos below are for all files in this project.
// TODO: Enable mouse support.
// TODO: Make input easier to interface with.
// TODO: Increase gfx support with common functions.
// TODO: Add library for game support.
// TODO: Enable WAV playback support.
// TODO: Make variation of library that enables OpenGL support.
// TODO: Improve debugging code.
// TODO: Do as much of main loop in library.
// TODO: Add in support for changing mouse cursor.
// TODO: Add in font support.

#ifdef __cplusplus  // choose what c++ io lib to use
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "SDL2/SDL.h" // include SDL lib for gfx + sound install SDL in compliers include directory!
#include "gfxlib.h" // general gfx lib I made for SDL

int speed = 3;
int espeed = 2;
int FPS = 60;
#define screenx 620
#define screeny 480
Uint32 waittime = 1000.0f/FPS;
Uint32 framestarttime = 0;
Sint32 delaytime;
/** BULLETS ARE CREATED */
int bulletw = 16;
int bulleth = 16;
/** BULLETS ARE DONE */
/**CHARS ARE MADE*/
int s1w = 16;
int s1h = 16;
int s1x = 0;
int s1y = 0;
int e1w = 16;
int e1h = 16;
int e1x = 300;
int e1y = 300;
/** CHARS ARE DONE */
int mousex;
int mousey;
int mouseon = 0;
int red = 0;
int green = 0;
int blue = 0;
int wait = 0;
int wait2 = 0;
bool left = 0;
bool right = 0;
bool up = 0;
bool down = 0;
bool shift = 0;

int main ( int argc, char** argv ) { // init for SDL
    /** INIT. ALL LIBRARYS */
    initgfx(screenx, screeny); // open window with 620x480 res. with 8 bit color
    /** INIT. ALL LIBRARYS END */
    atexit(closegfx); // make sure SDL cleans up before exit
    clearscreen(0,0,0);
    //SDL_ShowCursor(SDL_DISABLE);
    /* program main loop */
    //displaybitmap("gfx/metroid.bmp", 0, 0); // set background.
    bool done = false; // make bool done for while statment
    while (!done) { // loop until done = true
        // message processing loop
        clearscreen(0, 0, 0, s1x, s1y, s1w, s1h);
        clearscreen(0, 0, 0, e1x, e1y, e1w, e1h);
        SDL_GetMouseState(&mousex, &mousey);
        SDL_Event event;
        done = overlap(s1x, s1y, s1w, s1h, e1x, e1y, e1w, e1h);
        while (SDL_PollEvent(&event)) {
            /** INPUT SETTINGS */
            switch (event.type) {
            case SDL_QUIT: // exit if the window is closed
                done = true; // set done to true for exit
                break; // end caseclearscreen(red, green, blue, s1x, s1y, s1w, s1h);
            case SDL_KEYDOWN: // check for keypresses
                if (event.key.keysym.sym == SDLK_ESCAPE) {done = true;}
                if (event.key.keysym.sym == SDLK_UP) {up = 1;}
                if (event.key.keysym.sym == SDLK_DOWN) {down = 1;}
                if (event.key.keysym.sym == SDLK_LEFT) {left = 1;}
                if (event.key.keysym.sym == SDLK_RIGHT) {right = 1;}
                if (event.key.keysym.sym == SDLK_s) {SDL_SaveBMP(screen, "screenshots/screenshot.bmp");}
                if (event.key.keysym.sym == SDLK_LSHIFT) {if (wait <= 300) {shift = 1; speed = 1;}}
                break; // end case
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_LSHIFT) {speed = 3; shift = 0; wait = 0;}
                if (event.key.keysym.sym == SDLK_UP) {up = 0;}
                if (event.key.keysym.sym == SDLK_DOWN) {down = 0;}
                if (event.key.keysym.sym == SDLK_LEFT) {left = 0;}
                if (event.key.keysym.sym == SDLK_RIGHT) {right = 0;}
                break; // end case
            } /** END INPUT SETTINGS */
        } // end of message processing
        /** LOGIC STARTS HERE */
        if (shift == 1) {wait++;}
        if (wait >= 300) {shift = 0; speed = 3;}
        if (up == 1) {s1y -= speed;}
        if (down == 1) {s1y += speed;}
        if (left == 1) {s1x -= speed;}
        if (right == 1) {s1x += speed;}
        if ((s1x + s1w) > screenx) {s1x = (screenx - s1w);}
        if ((s1y + s1h) > screeny) {s1y = (screeny - s1h);}
        if (s1x < 0) {s1x = 0;}
        if (s1y < 0) {s1y = 0;}
        if (shift == 0) {
            if ((s1x - e1x) < 0) {e1x -= espeed;}
            if ((s1x - e1x) > 0) {e1x += espeed;}
            if ((s1y - e1y) < 0) {e1y -= espeed;}
            if ((s1y - e1y) > 0) {e1y += espeed;}
        }
        /** LOGIC ENDS HERE */
        /** DRAWING STARTS HERE */
        if (shift == 0) {
            displaybitmap("gfx/s1.bmp", s1x, s1y, 0, 0, 0);
        } else {
            displaybitmap("gfx/s1sneek.bmp", s1x, s1y, 0, 0, 0);
        }
        displaybitmap("gfx/e1.bmp", e1x, e1y, 0, 0, 0);
        /** DRAWING ENDS HERE */
        update(); // finally, update the screen to make changes
        delaytime = waittime - (SDL_GetTicks() - framestarttime);
        if(delaytime > 0) {SDL_Delay((Uint32)delaytime);}
        framestarttime = SDL_GetTicks();
    } // end main loop
    /** CLEAN UP STARTS */
    cleangfx(); // free loaded bitmap
    /** CLEAN UP ENDS */
    printf("Exited cleanly\n"); // all is well (i think...)
    return 0; // return success!
}
