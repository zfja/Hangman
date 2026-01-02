#ifndef WORDBANK_H
#define WORDBANK_H
#include <iostream>
#include <fstream>
#include <dirent.h>
using namespace std;

class WordBank
{
    vector <string> categories;
    string word;
    public:
        WordBank();
        void ReturnGenres();
        string GetWord(const string& category);
        void AddWord(const string& category);
};

#endif