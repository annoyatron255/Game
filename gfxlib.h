/** gfxlib.h a simple easy lirary
 *  for controling gfx SDL functions.
 */

#ifndef gfxlib_h
#define gfxlib_h
#include <SDL2/SDL.h>
#include <cstdio>

SDL_Window* hardwin = 0;
SDL_Surface* screen = 0;
SDL_Rect dstrect;
SDL_Rect partrect;

int initgfx(int x, int y) {
    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return 1;
	}
	else
	{
		//Create window
		hardwin = SDL_CreateWindow( "SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN );
		if( hardwin == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return 1;
		}
		else
		{
			//Get window surface
			screen = SDL_GetWindowSurface( hardwin );
		}
	}
	return 0;
}

int update(void) {
    SDL_UpdateWindowSurface(hardwin);
    return 0; // return success!
}

int displaybitmap(const char* file, int x, int y) {
    SDL_Surface* Surf_Return = 0;
    if((Surf_Return = SDL_LoadBMP(file)) == 0) {
        return 0;
    }
    dstrect.x = x;
    dstrect.y = y;
    SDL_BlitSurface(Surf_Return, 0, screen, &dstrect);
    SDL_FreeSurface(Surf_Return);
    return 0; // return success!
}

int displaybitmap(const char* file, int x, int y, int x2, int y2, int w, int h) {
    SDL_Surface* Surf_Return = 0;
    if((Surf_Return = SDL_LoadBMP(file)) == 0) {
        return 0;
    }
    dstrect.x = x;
    dstrect.y = y;
    partrect.x = x2;
    partrect.y = y2;
    partrect.w = w;
    partrect.h = h;
    SDL_BlitSurface(Surf_Return, &partrect, screen, &dstrect);
    SDL_FreeSurface(Surf_Return);
    return 0; // return success!
}

int displaybitmap(const char* file, int x, int y, int r, int b, int g) {
    SDL_Surface* Surf_Return = 0;
    if((Surf_Return = SDL_LoadBMP(file)) == 0) {
        return 0;
    }
    dstrect.x = x;
    dstrect.y = y;
    SDL_SetColorKey(Surf_Return, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Return->format, r, g, b));
    SDL_BlitSurface(Surf_Return, 0, screen, &dstrect);
    SDL_FreeSurface(Surf_Return);
    return 0; // return success!
}

int displaybitmap(const char* file, int x, int y, int x2, int y2, int w, int h, int r, int g, int b) {
    SDL_Surface* Surf_Return = 0;
    if((Surf_Return = SDL_LoadBMP(file)) == 0) {
        return 0;
    }
    dstrect.x = x;
    dstrect.y = y;
    partrect.x = x2;
    partrect.y = y2;
    partrect.w = w;
    partrect.h = h;
    SDL_SetColorKey(Surf_Return, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Return->format, r, g, b));
    SDL_BlitSurface(Surf_Return, &partrect, screen, &dstrect);
    SDL_FreeSurface(Surf_Return);
    return 0; // return success!
}

int clearscreen(int r, int g, int b) {
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, r, g, b)); // R, G, B backround.
    return 0; // return success!
}

int clearscreen(void) {
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    return 0; // return success!
}

int clearscreen(int r, int g, int b, int x, int y, int w, int h) {
    partrect.x = x;
    partrect.y = y;
    partrect.w = w;
    partrect.h = h;
    SDL_FillRect(screen, &partrect, SDL_MapRGB(screen->format, r, g, b));
    return 0; // return success!
}


int cleangfx(void) {
    SDL_FreeSurface(screen);
    return 0; // return success!
}

void closegfx(void) {
    SDL_FreeSurface(screen);
}

int overlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    if ((((abs(((x2+(w2/2))-(x1+(w1/2)))))<((w1+w2)/2))&((abs(((y2+(h2/2))-(y1+(h1/2)))))<((h1+h2)/2))) == 1) {
        return true;
    } else {
        return false;
    }
}

int touching(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    if ( (((abs(((x2+(w2/2))-(x1+(w1/2)))))<=((w1+w2)/2))&((abs(((y2+(h2/2))-(y1+(h1/2)))))<=((h1+h2)/2))) == 1) {
        return true;
    } else {
        return false;
    }
}

#endif
