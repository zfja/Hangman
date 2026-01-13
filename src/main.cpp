#include "Game.h"
#include "Player.h"
#include "Multiplayer.h"
#include "WordBank.h"
#include "Singleplayer.h"

int main()
{
    int option = 0;
    string player, word ;
    cout << "\033[2J\033[1;1H";

    do
    {
        cout <<"\nWybierz:\n (1) Tryb singleplayer\n (2) Tryp multiplayer\n (3) Opcje\n (4) Wyjdz\n  > ";
        cin >> option;
        
        switch(option)
        {
            case 1:
                {
                    int opt;
                    int genre;
                    float p;
                
                    Player *P(nullptr);
                    cout << "\nPodaj nazwe gracza: \n  > ";
                    cin >> player;
                    cin.ignore(100, '\n');
                    P = new Player(player);
                    cout <<"\nWybierz kategorię:\n";

                    WordBank wordbank;
                    wordbank.ReturnGenres();
                    cout << "  \n  > ";
                    cin >> genre;
                    
                    cout << "\033[2J\033[1;1H";

                    do
                    {   
                        p = P->GetPoints();
                        
                        string word;
                        word = wordbank.GetRandomWord(genre);

                        Game game(word);
                        Singleplayer singleplayer(word);
                        cin.ignore();
                        singleplayer.SPlay(*P);
                        game.Reset();

                        P->SetPoints(p + P->GetPoints());

                        singleplayer.SStats(*P);

                        do
                        {
                            cout <<"\n \nGrasz dalej?\n (1) Tak\n (2) Tak, ale zmien kategorie\n (3) Nie\n  > ";
                            cin >> opt;

                            if (opt != 1 && opt != 2 && opt != 3)
                                cout << "Podano niepoprawną opcję.\n";

                            if (opt == 2)
                            {
                                cout <<"\nWybierz kategorię:\n";
                                wordbank.ReturnGenres();
                                cout << "  \n  > ";
                                cin >> genre;
                            }
                            if (opt == 3)
                                cout << "Gracz " << P->GetPlayer() << " wygrał!\n"; 

                        }while (opt != 1 && opt != 2 && opt != 3);

                    }while(opt != 3);
                
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
                    cin.ignore(100, '\n');
                    P1 = new Player(player);

                    cout << "\nPodaj nazwe gracza 2: \n  > ";
                    cin >> player2;
                    cin.ignore(100, '\n');
                    cout << "\n";
                    P2 = new Player(player2);

                    cout << "\033[2J\033[1;1H";

                    do
                    {   
                        p1 = P1->GetPoints();
                        p2 = P2->GetPoints();

                        cout << "\nPodaj slowo dla " << player <<"!\n  > ";
                        cin >> word;
                        cin.ignore(1000, '\n');

                        Game game1(word);
                        Multiplayer multiplayer1(word);
                        multiplayer1.MPlay(*P1);
                        game1.Reset();

                        cout << "\nPodaj słowo dla " << player2 <<"!\n  > ";
                        cin >> word;
                            
                        Game game2(word);
                        Multiplayer multiplayer2(word);
                        cin.ignore();
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

                            if (opt == 2)
                            {
                                cout << '\n';
                                if (P1->GetPoints() > P2 ->GetPoints())
                                    cout << "Gracz " << P1->GetPlayer() << " wygrał!\n"; 
                                else if (P1->GetPoints() < P2 ->GetPoints())
                                    cout << "Gracz " << P2->GetPlayer() << " wygrał!\n"; 
                            }

                        }while (opt != 1 && opt != 2);

                    }while(opt != 2);
                    
                    break;
                }

            case 3:
            {
                int opt;
                WordBank wordbank;
                cout << "\033[2J\033[1;1H";

                do
                {
                    cout <<"\n \nWybierz opcje:\n (1) Dodaj nowa kategorie\n (2) Dodaj slowo do istniejacej kategori\n (3) Wyjdz\n  > ";
                    cin >> opt;

                    switch(opt)
                    {
                        case 1:
                        {
                            int optt = 0;
                            do
                            {
                                string category;
                                cout << "\n \nObecnie istniejace kategorie: \n";
                                wordbank.ReturnGenres();

                                cout << "\n \nPodaj kategorie, ktora chcesz dodac:\n  > ";
                                cin >> category;

                                wordbank.AddCategory(category);

                                cout << "\n \nObecnie istniejace kategorie: \n";
                                wordbank.ReturnGenres();

                                do
                                {
                                    cout << "\033[2J\033[1;1H";
                                    cout <<"\n \nCzy chcesz wprowadzic jeszcze jakies zmiany?\n (1) Tak\n (2) Nie\n  > ";
                                    cin >> optt;

                                    if (optt != 1 && optt != 2)
                                        cout << "Podano niepoprawną opcję.\n";

                                } while (optt != 1 && optt != 2);
                                
                            } while (optt == 1);
                            
                            break;
                        }
                        case 2:
                        {
                            int optt = 0;
                            do
                            {
                                string word;
                                int i;
                                cout << "\n \nObecnie istniejace kategorie: \n";
                                wordbank.ReturnGenres();
                                cout << "\n \nDo ktorej kategorii chcesz dodac slowo:\n  > ";
                                cin >> i;
                                cout << "\n \nPodaj slowo ktore chcesz dodac:\n  > ";
                                cin >> word;

                                wordbank.AddWord(wordbank.ReturnGenre(i), word);
                                
                                do
                                {
                                    cout << "\033[2J\033[1;1H";
                                    cout <<"\n \nCzy chcesz wprowadzic jeszcze jakies zmiany?\n (1) Tak\n (2) Nie\n  > ";
                                    cin >> optt;

                                    if (optt != 1 && optt != 2)
                                        cout << "Podano niepoprawną opcję.\n";

                                } while (optt != 1 && optt != 2);
                                
                            } while (optt == 1);

                            cout << "\033[2J\033[1;1H";
                            break;
                        }
                        case 3:
                            break;

                        default:
                            break;
                    }

                    if (opt != 1 && opt != 2 && opt != 3)
                        cout << "Podano niepoprawną opcję.\n";

                }while (opt != 1 && opt != 2 && opt != 3);

                break;
            }

            case 4:
                break;

            default:
                cout << "Podano niepoprawną opcje.\n";
                break;
        }
    }while(option > 0 && option < 4);

    return 0;
}