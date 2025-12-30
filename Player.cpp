#include "Player.h"


Player::Player(string player)
{
    this->player = player;
    points = 0;
    streak = 0;
}

void Player::SetPoints(float points)
{
    this->points = points;
}

void Player::SetStreak(int IsWon)
{
    if (IsWon == 1)
        streak += 1;
    if (IsWon == 0)
        streak = 0;
}

string Player::GetPlayer()
{
    return player;
}

float Player::GetPoints()
{
    return points;
}

int Player::GetStreak()
{
    return streak;
}