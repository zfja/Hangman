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

string WordBank::ReturnGenre(int i)
{
    return categories[i];
}

string WordBank::GetWord(const string& category)
{
    return "";
}

void WordBank::AddWord(const string& category, const string& word)
{
    string val;
    int i = 0;

    ifstream ifile;
    ifile.open(category);
    while (ifile >> val)
        i++;
    ifile.close();

    ofstream ofile;
    ofile.open(category, ios_base::app);
    ofile << '\n' << i/2 + 1 << " " + word;
    ofile.close();
}

void WordBank::AddCategory(const string& category)
{
    for (int i = 0; i < categories.size(); i++)
    {
        if (categories[i].substr(0, categories[i].size() - 4) == category)
        {
            cout << "Podana kategoria juz istnieje!\n";
            return;
        }    
    }
    
    ofstream(category+".txt");
    categories.push_back(category+".txt");
}