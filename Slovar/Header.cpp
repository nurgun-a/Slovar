#include "Header.h"

void read(map<string, int>& L)
{
    ifstream fin;
    locale locRus("RUS");
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
            transform(str.begin(), str.end(), str.begin(), bind1st(mem_fun(&ctype<char>::tolower), &use_facet<std::ctype<char> >(locRus)));//в нижний регистр     
            str = regex_replace(str, reg, "");
            //transform(str.begin(), str.end(), str.begin(), ::tolower);
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
