CXX=g++

SDL_FRAMEWORK=-F./ -framework SDL2
SDL_INCLUDE=-I./SDL2.framework/Versions/A/Headers

CFLAGS=-c $(SDL_INCLUDE)
LFLAGS=$(SDL_FRAMEWORK) -o

GameExec: main.o General.o Gfx.o Input.o Sprite.o
	$(CXX) $(LFLAGS) $@ $^

Sprite.o: Sprite.cpp
	$(CXX) $(CFLAGS) $^

Input.o: Input.cpp
	$(CXX) $(CFLAGS) $^

Gfx.o: Gfx.cpp
	$(CXX) $(CFLAGS) $^

General.o: General.cpp
	$(CXX) $(CFLAGS) $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o GameExec
