#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
    string player;
    float points;
    int streak;
    public:
        Player(string player);
        void SetPoints(float points);
        void SetStreak(int IsWon);
        string GetPlayer();
        float GetPoints();
        int GetStreak();
        
};

#endif