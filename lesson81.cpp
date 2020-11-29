#include <iostream>
#include <string>
using namespace std;

/*
*  ключевое слово this
*/

class Human //class - пользовательский тип данных
{
public:      //модификатор доступа
    int age; //поле класса
    int weight;
    string name;

    void Print() //функция класса
    {
        cout << "Name " << name << "\nAge " << age << "\nWeight " << weight << endl
             << endl;
    }
};

/*------------------------------------------*
*          пример применения this           *
*-------------------------------------------*/
class Point
{
private:
    int X;
    int Y;

public:
    Point() //конструктор по умолчанию
    {
        X = 0;
        Y = 0;
    }

    Point(int valueX, int valueY) //перегрузка
    {
        X = valueX;
        Y = valueY;
    }

    int GetX()
    { //геттер
        return X;
    }

    void SetX(int X) //инициализируем параметр X
    {                //по умолчанию, компилятор работает
        this->X = X; //только в этой области и под Х
    }                //понимает данный параметр, а не
                     //поле private: X. Для избежания данной
                     //ошибки, применяют ключевое слово this
                     //которое точно определяет к какому из
                     //X присваетвается значение

    void Print()
    {
        cout << "X = " << X << "\tY = " << Y << endl
             << endl;
    }
};

class CoffeeGrinder
{
private:
    bool CheckVoltage()
    {
        return random() % 2;
    }

public:
    void Start()
    {
        for (int i = 0; i < 20; i++)
        {
            if (CheckVoltage())
            {
                cout << "VjuHHHH !!!" << endl;
            }
            else
            {
                cout << "Beep Beep" << endl;
            }
        }
    }
};

int main()
{
    Point a;
    a.SetX(5);
    a.Print();

    return 0;
}