#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * перегрузка операторов потокого ввода вывода
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
private:
    int X;
    int Y;
    int Z;

    friend ostream &operator<<(ostream &os, const Point &point);
    friend istream &operator>>(istream &is, Point &point);
};

ostream &operator<<(ostream &os, const Point &point) //NOTE перегрузка оператора ввода
{
    os << point.X << " " << point.Y << " " << point.Z;
    return os;
}

istream &operator>>(istream &is, Point &point) //NOTE перегрузка оператора вывода
{
    is >> point.X >> point.Y >> point.Z;
    return is;
}

int main()
{
    // Point point(423, 754, 674);
    //cout << point;

    string path = "./execute/lesson119.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())
    {
        cout << "Error open file!" << endl;
    }
    else
    {
        cout << "File is open!" << endl;
        // fs << point << "\n";                     //NOTE запись в файл прерменной Point
        while (true) //NOTE чтение из файла до конца файла и вывод содержимого в консоль
        {
            Point p;
            fs >> p;
            if (fs.eof())
            {
                break;
            }
            cout << p << endl;
        }
    }
    fs.close();

    return 0;
}