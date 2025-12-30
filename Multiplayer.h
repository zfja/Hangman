#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H
#include "Game.h"
using namespace std;

class Multiplayer : public Game
{
    public: 
        Multiplayer(string& word);
        void MPlay(Player& player);
        void MStats(Player player1, Player player2) ;
};

#endif