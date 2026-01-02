#include "GameDisplay.h"
#include "Game.h"
#include "Player.h"
#include "Multiplayer.h"
#include "WordBank.h"
#include "Singleplayer.h"

int main()
{
    int option = 0;
    string player, word;
    cout << "\033[2J\033[1;1H";

    do
    {
        cout <<"\nWybierz:\n (1) Tryb singleplayer\n (2) Tryp multiplayer\n (3) Opcje\n (4) Wyjdz\n  > ";
        cin >> option;
        
        switch(option)
        {
            case 1:
                {
                    cout << "WYBRANO 1 OPCJE\n";
                    return 0;
                    
                    // int opt;
                    // float p;
                
                    // Player *P(nullptr);
                    // cout << "\nPodaj nazwe gracza: \n  > ";
                    // cin >> player;
                    // P = new Player(player);

                    // WordBank wordbank;
                    // wordbank.ReturnGenres();

                    

                    // do
                    // {   
                    //     p = P->GetPoints();

                    //     cout << "\nPodaj slowo dla " << player <<"!\n  > ";
                    //     cin >> word;

                    //     Game game(word);
                    //     Singleplayer singleplayer(word);
                    //     singleplayer.SPlay(*P);
                    //     game.Reset();

                    //     P->SetPoints(p + P->GetPoints());

                    //     singleplayer.SStats(*P);

                    //     do
                    //     {
                    //         cout <<"\n \nGrasz dalej?\n (1) Tak\n (2) Nie\n  > ";
                    //         cin >> opt;

                    //         if (opt != 1 && opt != 2)
                    //             cout << "Podano niepoprawną opcję.\n";

                    //     }while (opt != 1 && opt != 2);

                    // }while(opt != 2);
                
                    break;
                }

            case 2:
                {
                    int opt;
                    float p1, p2;
                    string player2;


                    Player *P1(nullptr);
                    Player *P2(nullptr);

                    cout << "\nPodaj nazwe gracza 1: \n  > ";
                    cin >> player;
                    P1 = new Player(player);

                    cout << "\nPodaj nazwe gracza 2: \n  > ";
                    cin >> player2;
                    cout << "\n";
                    P2 = new Player(player2);

                    cout << "\033[2J\033[1;1H";

                    do
                    {   
                        p1 = P1->GetPoints();
                        p2 = P2->GetPoints();

                        cout << "\nPodaj slowo dla " << player <<"!\n  > ";
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
                cout << "WYBRANO 1 OPCJE\n";
                return 0;
                
                break;

            case 4:
                break;

            default:
                cout << "Podano niepoprawną opcje.\n";
                break;
        }
    }while(option > 0 && option < 4);

    return 0;
}