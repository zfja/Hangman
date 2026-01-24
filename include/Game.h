#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <cctype> // z tej biblioteki uzywam to upper ktory zmienia a -> A
#include <vector>
#include <cstring> // uzywam strcpy ktory kopiuje string do tablicy charow
using namespace std;

class Game
{
    string word;
    float points_counter;
    static int count;
    static int tries;

    char *word_letters; // konik - odgadywane slowo przekonwertowane w WIELKIE litery
    char *letters_guessed; // _ _ _ _ _ (tyle ile ma słowo ma liter tyle _,)
    vector <char> letters; // zbior liter niepoprawnie odgadnietych
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