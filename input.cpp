#include <stdio.h>
#include <SDL.h>
#include "input.h"

int inputLoop() {
    SDL_Event event;
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
            //if (event.key.keysym.sym == SDLK_s) {SDL_SaveBMP(screen, "screenshots/screenshot.bmp");}
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
    return 0;
}
