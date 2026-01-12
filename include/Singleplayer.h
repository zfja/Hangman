#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H
#include "Game.h"
#include "WordBank.h"
using namespace std;

class Singleplayer : public Game
{
    public: 
        Singleplayer(string& word);
        void SPlay(Player& player);
        void SStats(Player player);
};

#endif