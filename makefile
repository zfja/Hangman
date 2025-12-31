CXX = g++
CXXFLAGS = -Wall
LFLAGS =

OBJS = main.o GameDisplay.o Game.o Player.o Multiplayer.o Singleplayer.o WordBank.o

all: prog

prog: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o prog

.PHONY: all clean