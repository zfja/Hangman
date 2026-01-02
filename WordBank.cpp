#include "WordBank.h"

WordBank::WordBank()
{
    DIR* dir = opendir(".");
    struct dirent* file;
    
    while ((file = readdir(dir)) != nullptr) 
    {
        string name = file->d_name;
        
        if (name.find(".txt") != string::npos)
            categories.push_back(name);
    }

    closedir(dir);
    
}

void WordBank::ReturnGenres()
{
    for (int i = 0; i < categories.size(); i++)
        cout << " (" << i+1 << ") " << categories[i].substr(0, categories[i].size() - 4) << "\n";
}

string WordBank::GetWord(const string& category)
{
    return "";
}

void WordBank::AddWord(const string& category)
{

}