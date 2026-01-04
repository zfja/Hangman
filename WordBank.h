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
        string ReturnGenre(int i);
        string GetWord(const string& category);
        void AddWord(const string& category, const string& word);
        void AddCategory(const string& category);
};

#endif