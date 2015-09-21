#ifndef Gfx_h
#define Gfx_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

namespace gfx {
	int gfxinit(int w,int h);
	void update();
	void clearScreen(int r, int g, int b);

	void drawRect(SDL_Rect rect, int r, int g, int b);
	SDL_Texture* createTexture(const char* file);

	void drawTexture(SDL_Texture* texture, SDL_Rect rect);
	void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b);

	void close();
}

#endif
