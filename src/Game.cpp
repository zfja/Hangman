#include "Game.h"

int Game::tries = 0;
int Game::count = 0;

Game::Game()
{
}

Game::~Game()
{
    delete display;
}

Game::Game(string& word)
{
    points_counter = 0;
    
    this->word = "";

    for (char& i : word) 
        this->word += toupper(i);
    
    display = new GameDisplay(this->word);
    display->Stickman(0, points_counter);
    display->Guessed(' ');
    display->Alphabet();
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
    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {
        if (display->GetLettersGuessed()[i] != letter)
        {
            if (display->GetWordLetters()[i] == letter)
                count++;
        }
        else
            return -1;
    }

    for (char i : display->GetAlphabeth()) 
    {
        if (i == letter) 
            return -1;
    }

    return count;
}

void Game::Play(const char& letter)
{
    if (IsTrue(letter) >= 0)
        count += IsTrue(letter);

    if (count <= word.length() && tries < 8)
    {
        if (IsTrue(letter) < 0) // podano juz odgadnieta litere
        {
            display->Stickman(tries, points_counter);   
            display->Guessed(letter);
            display->Alphabet();

        }
        if (IsTrue(letter) == 0) // bledna litera
        {
            tries++;
            points_counter -= tries * 5.21;
            display->Stickman(tries, points_counter);   
            display->Guessed(letter);
            display->Alphabet(letter);
        }
        if (IsTrue(letter) > 0) // poprawna litera
        {
            points_counter += IsTrue(letter) * word.length() * 21.37;
            display->Stickman(tries, points_counter);
            display->Guessed(letter);
            display->Alphabet();
        }
    }
}

int Game::IsWon(const char& letter)
{
    if (count == word.length())
    {            
        display->Stickman(tries, points_counter);
        display->Guessed(letter);
        display->Alphabet(tries);

        cout << "Wygrales! \n";

        return 1;
    }
    if (tries == 8)
    {
        display->Stickman(7, points_counter);   
        display->Guessed(letter);
        display->Alphabet(tries);

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