#ifndef WORDBANK_H
#define WORDBANK_H
#include <iostream>
#include <fstream>
using namespace std;

class WordBank
{
    string *genres;
    string word;
    public:
        WordBank();
        void ReturnGenres();
        string GetWord();
        void AddWord(const string& filename);
};

#endif