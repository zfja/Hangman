#ifndef WORDBANK_H
#define WORDBANK_H

using namespace std;
#include <iostream>
#include <fstream>

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