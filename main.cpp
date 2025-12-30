#include "GameDisplay.h"
#include "Game.h"
#include "Player.h"
#include "Multiplayer.h"
#include "WordBank.h"
#include "Singleplayer.h"

int main()
{
    int option = 0;
    string player, player2, word;

    Player *P1(nullptr);
    Player *P2(nullptr);

    do
    {
        system("clear");
        system("clear");
        cout <<"\nWybierz:\n (1) Tryb singleplayer\n (2) Tryp multiplayer\n (3) Opcje\n (4) Wyjdź\n  > ";
        cin >> option;
        
        switch(option)
        {
            case 1:
                cout << "aaa\n" ;
                break;

            case 2:
                {
                    int opt;
                    int games_played = 0;

                    float p1;
                    float p2;

                    cout << "\nPodaj nazwę gracza 1: \n  > ";
                    cin >> player;
                    P1 = new Player(player);

                    cout << "\nPodaj nazwę gracza 2: \n  > ";
                    cin >> player2;
                    cout << "\n";
                    P2 = new Player(player2);

                    system("clear");

                    do
                    {   
                        p1 = P1->GetPoints();
                        p2 = P2->GetPoints();

                        cout << "\nPodaj słowo dla " << player <<"!\n  > ";
                        cin >> word;

                        Game game1(word);
                        Multiplayer multiplayer1(word);
                        multiplayer1.MPlay(*P1);
                        game1.Reset();

                        cout << "\nPodaj słowo dla " << player2 <<"!\n  > ";
                        cin >> word;
                            
                        Game game2(word);
                        Multiplayer multiplayer2(word);
                        multiplayer2.MPlay(*P2);
                        game2.Reset();

                        P1->SetPoints(p1 + P1->GetPoints());
                        P2->SetPoints(p2 + P2->GetPoints());

                        multiplayer2.MStats(*P1, *P2);

                        do
                        {
                            cout <<"\n \nGrasz dalej?\n (1) Tak\n (2) Nie\n  > ";
                            cin >> opt;

                            if (opt != 1 && opt != 2)
                                cout << "Podano niepoprawną opcję.\n";

                        }while (opt != 1 && opt != 2);

                    }while(opt != 2);
                
                    break;
                }

            case 3:
                cout << "aaa\n" ;
                break;

            case 4:
                break;

            default:
                cout << "Podano niepoprawną opcję.\n";
                break;
        }
    }while(option > 0 && option < 4);

    return 0;
}