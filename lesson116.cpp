#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * чтение данных из файла
 */

int main()
{
    string path = "./execute/lesson115.txt";

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Error open file!" << endl;
    }
    else
    {
        cout << "File is open." << endl;
        string str;

        while (!fin.eof()) //NOTE eof считывает до конца файла
        {
            str = "";
            getline(fin, str); //NOTE считывание по строкам
            cout << str << endl;
        }
    }

    fin.close();

    return 0;
}