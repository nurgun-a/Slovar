#include "Header.h"

void main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //setlocale(LC_ALL, "ru");

    map<string, int> sl;
    read(sl);
    for (auto it = sl.begin(); it != sl.end(); it++)
        cout << it->first << " " << it->second << "\n";
    write(sl);   
    system("pause");

}