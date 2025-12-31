#include "GameDisplay.h"

GameDisplay::GameDisplay()
{

}

GameDisplay::GameDisplay(const string &word)
{
    word_letters = new char [word.length() + 1];
    strcpy(word_letters, word.c_str());

    letters_guessed = new char [word.length() + 1];
    for (int i = 0; i < word.length(); i++)
    {
        letters_guessed[i] = '_';
    }
    letters_guessed[word.length()] = '\0';
}

GameDisplay::~GameDisplay()
{
    delete [] word_letters;
    delete [] letters_guessed;
}

char * GameDisplay::GetWordLetters()
{
    return word_letters;
}

char * GameDisplay::GetLettersGuessed()
{
    return letters_guessed;
}

void GameDisplay::Stickman(int tries, float points)
{
    switch(tries)
    {
        case 0:
            system("clear");
            system("clear");
            cout <<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
            cout << '\n';
            cout << '\n';
            cout << '\t' << "\tliczba pozostalych prob: " << 8 - tries << '\n';
            cout << '\t' << "\tpunkty: " << points << '\n';
            cout << '\n';
            cout << "==========\n \n";
            break;
        case 1:
            system("clear");
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
            system("clear");
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
            system("clear");
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
            system("clear");
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
            system("clear");
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
            system("clear");
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
            system("clear");
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

void GameDisplay::Guessed(const char& letter)
{
    for (int i = 0; i < strlen(word_letters) ; i++)
    {
        if (word_letters[i] == letter && letters_guessed[i] != letter)
            letters_guessed[i] = letter;

        cout << letters_guessed[i] << " ";
    }
    cout << '\n' << '\n';
}

vector <char> GameDisplay::GetAlphabeth()
{
    return letters;
}

void GameDisplay::Alphabeth(const char& letter)
{
    bool exists;

    for (char i : letters)
    {
        if (i == letter)
        {
            exists = true;
            break;
        }
    }

    if (!exists) 
        letters.push_back(letter);
    

    cout << '\n';
    for (int i = 0; i < letters.size(); i++)
        cout << letters[i] << "  ";

    cout << '\n' << '\n' << "  > ";
}

void GameDisplay::Alphabeth()
{
    cout << '\n';
    for (int i = 0; i < letters.size(); i++)
        cout << letters[i] << "  ";

    cout << '\n' << '\n'  << "  > ";
}