int gfxinit(int x,int y);
int update();
int clearScreen(int r, int g, int b);
int fillRect(SDL_Rect rect, int r, int g, int b);
SDL_Texture* createTexture(const char* file);
int drawTexture(SDL_Texture* texture, SDL_Rect rect);
int drawLine(int x1, int y1, int x2, int y2, int r, int g, int b);
int close();
