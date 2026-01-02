#ifndef GAME_H
#define GAME_H
#include "GameDisplay.h"
#include "Player.h"
#include <cctype>
using namespace std;

class GameDisplay;

class Game
{
    string word;
    GameDisplay *display;
    float points_counter;
    static int count;
    static int tries;
    public:
        Game();
        ~Game();
        Game(string& word);
        float GetPointsCounter();
        int GetTries();
        int IsTrue(const char& letter);
        void Play(const char& letter);
        int IsWon(const char& letter);
        void Reset();
};

#endif