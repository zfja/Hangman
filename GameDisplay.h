#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Game;

class GameDisplay
{
    char *word_letters;
    char *letters_guessed;
    vector <char> letters;
    public:
        GameDisplay();
        GameDisplay(const string &word);
        ~GameDisplay();
        char *GetWordLetters();
        char *GetLettersGuessed();
        void Stickman(int tries, float points);
        void Guessed(const char& letter);
        vector <char> GetAlphabeth();
        void Alphabeth(const char& letter);
        void Alphabeth();
};

#endif