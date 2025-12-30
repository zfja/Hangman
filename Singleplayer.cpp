#include "Singleplayer.h"

Singleplayer::Singleplayer(string& word) : Game(word)
{
}

void Singleplayer::SPlay(Player& player)
{
while(true)
    {
        char letter;
        float p;
        cin >> letter;

        letter = toupper(letter);

        Play(letter); //gra wisielec
        player.SetPoints(GetPointsCounter()); // przypisanie punktow

        int result = IsWon(letter);

        if (result == 1)  
        {
            player.SetStreak(result); // przypisanie streaku
            break;
        }
        if (result == 0)
        {
            player.SetStreak(result); // zerowanie streaku
            break;
        }
    }
}

void Singleplayer::SStats(Player player)
{
    system("clear");
    cout << "\n \n   ";
    cout << player.GetPlayer() << "\n ";
    cout << "punkty skumulowane: " << player.GetPoints() << "\n ";
    if (player.GetStreak() != 0)
        cout << "streak: " <<player.GetStreak() << "\n  ";
}