#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * fstream чтение/запись данных
 */

int main()
{
    string path = "./execute/lesson118.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app); //NOTE путь к файлу, разрешаем читать|записывать|добавлять в файл

    if (!fs.is_open())
    {
        cout << "Error open file" << endl;
    }
    else
    {
        int value;
        string msg;
        cout << "File is open" << endl;

        cout << "Input 1 for write message in file.:" << endl;
        cout << "Input 2 for read messags in file:" << endl;
        cin >> value;

        if (value == 1)
        {
            cout << "Input your`s message:" << endl;
            cin >> msg;
            fs << msg << "\n";
        }
        if (value == 2)
        {
            cout << "Reading file:" << endl;
            while (!fs.eof())
            {
                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
        }
    }
    fs.close();
    return 0;
}