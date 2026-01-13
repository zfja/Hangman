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
    points_counter = 0;
    tries = 0;
    count = 0;
    
    this->word = "";

    for (char& i : word) 
        this->word += toupper(i);
    
    word_letters = new char [word.length() + 1];
    strcpy(word_letters, this->word.c_str());

    letters_guessed = new char [word.length() + 1];
    for (int i = 0; i < word.length(); i++)
    {
        letters_guessed[i] = '_';
    }
    letters_guessed[word.length()] = '\0';

    Stickman(0, points_counter);
    Guessed(' ');
    Alphabet();
}

float Game::GetPointsCounter()
{
    return points_counter;
}

int Game::GetTries()
{
    return tries;
}

int Game::IsTrue(const char& letter)
{    
    for (char i : letters) 
    {
        if (i == letter) 
            return -1; //-1 powtarza sie z niezgadnietymi - dziala            -1 jest juz w nieodgadnietych 
    }
    
    int counter = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word_letters[i] == letter)
            if (letters_guessed[i] != letter)
                counter++; //jest w slowie, ale nie jest odgadniete - dziala           counetr - liczba charow w zgadywaym slowie moze byc tez 0
            if (letters_guessed[i] == letter)
                return -1;
    }
    return counter; 
}

void Game::Play(const char& letter)
{
    int result = IsTrue(letter);   // albo liczba zgadnietych (0, 1, 2) albo -1 

    if (result >= 0)
        count += result;
    
    
    if (count <= word.length() && tries < 8)
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

int Game::IsWon(const char& letter)
{
    if (count == word.length())
    {            
        Stickman(tries, points_counter);
        Guessed(letter);
        Alphabet(tries);

        cout << "Wygrales! \n";

        return 1;
    }
    if (tries == 8)
    {
       Stickman(7, points_counter);   
        Guessed(letter);
        Alphabet(tries);

        cout << "Przegralas :( \n";

        return 0;
    }
    return -1;
}

void Game::Reset()
{
    tries = 0;
    count = 0;
}

//////////////

void Game::Alphabet(const char& letter)
{
    bool exists = false;

    for (char i : letters)
    {
        if (i == letter)
        {
            exists = true;
            break;
        }
    }

    if (exists == false) 
        letters.push_back(letter);
    

    cout << '\n';
    for (int i = 0; i < letters.size(); i++)
        cout << letters[i] << "  ";

    cout << '\n' << '\n' << "  > ";
}

void Game::Alphabet()
{
    cout << '\n';
    for (int i = 0; i < letters.size(); i++)
        cout << letters[i] << "  ";

    cout << '\n' << '\n'  << "  > ";
}

void Game::Guessed(const char& letter)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word_letters[i] == letter && letters_guessed[i] != letter)
            letters_guessed[i] = letter;

        cout << letters_guessed[i] << " ";
    }
    cout << '\n' << '\n';
}

void Game::Stickman(int tries, float points)
{
    switch(tries)
    {
        case 0:
            cout << "\033[2J\033[1;1H";
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << '\n';
            cout << '\n';
            cout << '\t' << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << '\t' << "\tpunkty: " << points << '\n';
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
        deafult:
            break;
    }
    
}
