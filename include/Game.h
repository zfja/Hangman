#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;

class Game
{
    string word;
    float points_counter;
    static int count;
    static int tries;

    char *word_letters;
    char *letters_guessed;
    vector <char> letters;
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

        void Alphabet(const char& letter);
        void Alphabet();
        void Guessed(const char& letter);
        void Stickman(int tries, float points);
};

#endif