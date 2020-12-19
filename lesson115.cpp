#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * сохранение данных в файл
 */

int main()
{
    string path = "lesson115.txt";
    ofstream fout;

    fout.open(path, ofstream::app);//NOTE Перегруженный метод open
                                    //если добавить ofstream::app, то
                                    //новые данные будут дописываться
                                    //в конец, не затирая существующие
    if (!fout.is_open())
    {
        cout << "Error open file" << endl;
    }
    else
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Введите число" << endl;
            int i;
            cin >> i;
            fout << i;
            fout << "\n";
        }
    }

    fout.close();

    return 0;
}