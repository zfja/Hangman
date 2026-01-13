CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
TARGET = prog

SOURCES = src/Game.cpp src/main.cpp src/Multiplayer.cpp src/Player.cpp src/Singleplayer.cpp src/WordBank.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

clear: clean

run: $(TARGET)
	./$(TARGET)