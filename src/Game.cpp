#include "Game.h"

int Game::tries = 0;
int Game::count = 0;
Game::Game() : word_letters(nullptr), letters_guessed(nullptr), points_counter(0)
{
    tries = 0;
    count = 0;
}

Game::~Game()
{
    delete [] word_letters;
    delete [] letters_guessed;
}

Game::Game(string& word) 
{
    // np. word = Konik
    points_counter = 0;
    tries = 0;
    count = 0;
    
    this->word = ""; //tutaj tworze pusty word poniewaz ...

    for (char& i : word) 
        this->word += toupper(i); //... tutaj "sklejam" go z wprowadzonego slowa zmieniajac wszystkie male litery w wielkie
    // na tym etapie juz mam KONIK
    word_letters = new char [word.length() + 1]; // a tu tworze juz z tego slowa w wielkich liter tablice charow
    strcpy(word_letters, this->word.c_str());
    // a tu mam 'K' 'O' 'N' 'I' 'K'         c_str() dodaje '\0' abym mogla tez z niego korzystac jako string
    letters_guessed = new char [word.length() + 1]; 
    for (int i = 0; i < word.length(); i++)
    {
        letters_guessed[i] = '_'; // tu tworze tablice _ _ _ _ _ 
    }
    letters_guessed[word.length()] = '\0'; //i na koncu rowniez dodaje '\0'

    Stickman(0, points_counter); //startow hangman
    Guessed(' '); // odrazu przerwa na alfabet aby gra nie przeskakiwala (wizualne zastosowanie)
    Alphabet(); // tak samo --||--
}

float Game::GetPointsCounter()
{
    return points_counter;
}

int Game::GetTries()
{
    return tries;
}

int Game::IsTrue(const char& letter) //zwraca -1 kiedy litera jest juz byla odgadnieta   albo zwraca ilosc liter odgadnietych
{    
    for (char i : letters) 
    {
        if (i == letter) 
            return -1; //jest juz w letters, byla odgadnieta(blednie)
    }
    
    int counter = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word_letters[i] == letter)
            if (letters_guessed[i] != letter)
                counter++; //jest w slowie tyle razy ile counter zliczy         MOZE BYC 0!
            if (letters_guessed[i] == letter)
                return -1; //jest juz w letters_guessed, byla odgadnieta(poprawnie)
    }
    return counter; 
}

void Game::Play(const char& letter) // skleja wszystko w jedno
{
    int result = IsTrue(letter);   // albo liczba zgadnietych (0, 1, 2) albo -1 jak juz odgadnieta 

    if (result >= 0) //wchodze w petle tylko jak odgadlam litere <=> zlicza ile juz liter odgadlam 0 jest oK!!!
        count += result;
    
    
    if (count <= word.length() && tries < 8) // upewnia sie ze ilosc odgadnietych liter jest mniejsza/rowna liter z slowa
    {
        if (result < 0) // podano juz odgadnieta litere
        {
            Stickman(tries, points_counter);   
            Guessed(letter);
            Alphabet(); 

        }
        if (result == 0) // bledna litera
        {
            tries++;
            points_counter -= tries * 5.21;
            Stickman(tries, points_counter);   
            Guessed(letter);
            Alphabet(letter); 
        }
        if (result > 0) // poprawna litera
        {
            points_counter += result * word.length() * 21.37;
            Stickman(tries, points_counter);
            Guessed(letter);
            Alphabet();
        }
    }
}

int Game::IsWon(const char& letter) // czy gra jest wygrana?
{
    if (count == word.length()) // jak liczba odgadnietych liter pokrywa sie z liczba ze slowa tak
    {            

        cout << "Wygrales! \n";

        return 1;
    }
    if (tries == 8) // jak liczba prob rowna sie 8 to nie ;/
    {
        Stickman(8, points_counter);
        for (int i = 0; i < word.length(); i++)
        cout << word_letters[i] << " ";
        cout << '\n' << '\n';
        Alphabet();
        cout << "Przegralas :( \n";
        return 0;
    }
    return -1; //czemu jeszcze to jest -1?? bo w multiplayer i singleplayer zawsze wychodzi w ta funkcje, jak sie nie spelnia stad -1
}

void Game::Reset() // resertuje staticy
{
    tries = 0;
    count = 0;
}

void Game::Alphabet(const char& letter) // dodaje liczbe do alfabetu blednie odgadnietych i wyswietla
{
    bool exists = false;

    for (char i : letters) //sprawdza czy nie jest juz w blednie odgadnietych
    {
        if (i == letter)
        {
            exists = true;
            break;
        }
    }

    if (exists == false) 
        letters.push_back(letter); // jak nie jest dodaje
    

    cout << '\n';
    for (int i = 0; i < letters.size(); i++) // i standardowo wypisuje
        cout << letters[i] << "  ";

    cout << '\n' << '\n' << "  > ";
}

void Game::Alphabet() // po prostu wyswietla
{
    cout << '\n';
    for (int i = 0; i < letters.size(); i++)
        cout << letters[i] << "  ";

    cout << '\n' << '\n'  << "  > ";
}

void Game::Guessed(const char& letter) // jak litera jest odgadnieta dodaje ja do odganietych czyli to jest to _ _ _ _ _ -> K _ _ _ K i wypisuje
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word_letters[i] == letter && letters_guessed[i] != letter)
            letters_guessed[i] = letter;

        cout << letters_guessed[i] << " ";
    }
    cout << '\n' << '\n';
}

void Game::Stickman(int tries, float points) //rysowanie stickamana
{
    switch(tries)
    {
        case 0:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << '\n';
            cout << '\t' << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << '\t' << "\tpunkty: " << points << '\n';
            cout << '\n';
            cout << '\n';
            cout << "==========\n \n";
            break;
        case 1:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "\t|\n";
            cout << "\t|" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "\t|" << "\tpunkty: " << points <<'\n';
            cout << "\t|\n";
            cout << "\t|\n";
            cout << "==========\n  \n";
            break;
        case 2:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "\t|" << "\tpunkty: " << points << '\n';
            cout << "\t|\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;
        case 3:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "   |    |" << "\tpunkty: " << points << '\n';
            cout << "\t|\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;
        case 4:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "  /|    |" << "\tpunkty: " << points << '\n';
            cout << "\t|\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;
        case 5:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "  /|\\   |" << "\tpunkty: " << points << '\n';
            cout << "\t|\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;      
        case 6:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostałych prob: " << 8 - tries << '\n';
            cout << "  /|\\   |" << "\tpunkty: " << points << '\n';
            cout << "  /     |\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;
        case 7:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   O    |" << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << "  /|\\   |" << "\tpunkty: " << points << '\n';
            cout << "  / \\   |\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
            break;
        case 8:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << "   +----+\n";
            cout << "   |    |\n";
            cout << "   X    |" << "\tliczba pozostalych prob: " << 0 << '\n';
            cout << "  /|\\   |" << "\tpunkty: " << points << '\n';
            cout << "  / \\   |\n";
            cout << "\t|\n";
            cout << "==========\n \n"; 
        deafult:
            break;
    }
    
}
