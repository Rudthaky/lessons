#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Запись/чтение объекта класса
 */

class Point
{
public:
    Point()
    {
        X = Y = Z = 0;
    }
    Point(int X, int Y, int Z)
    {
        this->X = X;
        this->Y = Y;
        this->Z = Z;
    }

    void Print()
    {
        cout << "X = " << X << "\tY = " << Y << "\tZ = " << Z << endl;
    }
    int X;
    int Y;
    int Z;
};

int main()
{
    string path = "./execute/lesson117.txt";
    ofstream fout;
    ifstream fin;
    Point point;

    cout << "Input Х: ";
    cin >> point.X;
    cout << endl;
    cout << "Input Y: ";
    cin >> point.Y;
    cout << endl;
    cout << "Input Z: ";
    cin >> point.Z;

//запись в файл
    fout.open(path, ofstream::app);
    if (!fout.is_open())
    {
        cout << "Error open file" << endl;
    }
    else
    {
        cout << "File is open" << endl;
        fout.write((char *)&point, sizeof(Point)); //NOTE первый параметр - указатель на char
                                                   // второй - размер объекта
    }
    fout.close();

//чтение из файла
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Error open file" << endl;
    }
    else
    {
        cout << "File is open" << endl;
        Point pnt;
        while (fin.read((char *)&pnt, sizeof(Point)))
        {
            pnt.Print();
        }
    }
    fin.close();
    return 0;
}