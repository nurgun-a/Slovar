#include "Header.h"

void read(map<string, int>& L)
{
    ifstream fin;
    string str;
    regex reg(R"([.,\/#!$%\^&\*;:{}=\«»"-_~—()])");
    fin.open("input2.txt", ios::in, ios::binary);
    if (!fin)
    {
        cout << "Ошибка чтениия!!!\nПроверьте файл" << endl;
    }
    else
    {
        while (fin >> str)
        {            
            //transform(str.begin(), str.end(), str.begin(), ::tolower);            
            str = regex_replace(str, reg, "");
            L[str]++;
        }
    }
    fin.close();
}


void write(map<string, int>& L)
{
    ofstream of;
    of.open("result.txt", ios::out, ios::binary);
    if (!of)
    {
        cout << "Ошибка записи!!!\nПроверьте файл" << endl;
    }
    else
    {
        for (auto it = L.begin(); it != L.end(); it++)
        {
            of << it->first << " " << it->second << "\n";
        }
    }
}
