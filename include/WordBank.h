#ifndef WORDBANK_H
#define WORDBANK_H
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include <vector>
using namespace std;

class WordBank
{
    vector <string> categories;
    string word;
    public:
        WordBank();
        void ReturnGenres();
        string ReturnGenre(int i);
        string GetRandomWord(int i);
        void AddWord(const string& category, const string& word);
        int CategorySize(const string& category);
        void AddCategory(const string& category);
};

#endif