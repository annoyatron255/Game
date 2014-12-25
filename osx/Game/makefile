CXX=g++

SDL_FRAMEWORK=-F./ -framework SDL2
SDL_FRAMEWORK_HEADER=-I./SDL2.framework/Versions/A/Headers

INCLUDE=-I./Game/gfxlib.h

CFLAGS=-c $(SDL_FRAMEWORK_HEADER) $(INCLUDE)
LFLAGS=$(SDL_FRAMEWORK) -o 

VPATH=Game

GameExec: main.o
	$(CXX) $(LFLAGS) $@ $^
	rm -rf *.o

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

clean:
	rm -rf GameExec
