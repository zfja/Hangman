#include "Multiplayer.h"

Multiplayer::Multiplayer(string& word) : Game(word)
{
}

void Multiplayer::MPlay(Player& player)
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

void Multiplayer::MStats(Player player1, Player player2)
{
    system("clear");
    cout << "\n \n   ";
    cout << player1.GetPlayer() << "\n ";
    cout << "punkty skumulowane: " << player1.GetPoints() << "\n ";
    if (player1.GetStreak() != 0)
        cout << "streak: " <<player1.GetStreak() << "\n  ";
        
    cout << "\n   ";
    cout << player2.GetPlayer() << "\n ";
    cout << "punkty skumulowane: " << player2.GetPoints() << "\n ";
    if (player2.GetStreak() != 0)
        cout << "streak: " << player2.GetStreak() << "\n  ";
}