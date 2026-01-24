#include "WordBank.h"

WordBank::WordBank()
{
    DIR* dir = opendir("."); //otwiera ten folder
    struct dirent* file; // ten dirent opisuje pliki systemowe generalnie jak to 
    // ciezko mi zrozumiec jak to DOKLADNIE dziala, ale znalazlam to tu https://cpp0x.pl/artykuly/Inne-artykuly/C-C++-Listowanie-plikow-biblioteka-dirent-h/53
    // i tym sie inspirowalam piszac 

    // ale ten dirent przechowuje infromacje o pliku 

    while ((file = readdir(dir)) != nullptr)  // doporki ten dir zwraca jakis plik to po nim leci, jak przestanie to przestaje bo juz nie ma plikow w folderze, on leci po wszystkim z folderu 
    {
        string name = file->d_name; // zczytuje z tego adresu pliku nazwe pliku
        
        if (name.find(".txt") != string::npos) // i tu jest ten if jak napotka z koncowka .txt to dopisuje do categories
            categories.push_back(name);
    }

    closedir(dir);
}

void WordBank::ReturnGenres() //wypisuje wszystkie pliki .txt 
{
    for (int i = 0; i < categories.size(); i++)
        cout << " (" << i+1 << ") " << categories[i].substr(0, categories[i].size() - 4) << "\n";
}

string WordBank::ReturnGenre(int i) 
{
    return categories[i-1];
}

string WordBank::GetRandomWord(int i) // daje slowo z wybranej kategorii
{
    float k = 0.0;
    int numer;
    string val;
    srand(time(0));
    numer = rand() % CategorySize(categories[i-1]) + 1;

    ifstream ifile;
    ifile.open(categories[i-1]);
    while (ifile >> val)
    {
        k += 0.5;
        if (k == numer)
            return val;
    }
    ifile.close();
    
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

int WordBank::CategorySize(const string& category)
{
    string val;
    int i = 0;

    ifstream ifile;
    ifile.open(category);
    while (ifile >> val)
        i++;
    ifile.close();

    return i/2;
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