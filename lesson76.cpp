#include <iostream>
#include <string>
using namespace std;

/*
*   геттеры и сеттеры
*   инкапсуляция
*/

class Human             //class - пользовательский тип данных
{
    public:             //модификатор доступа
        int age;        //поле класса         
        int weight;
        string name;

        void Print()    //функция класса
        {
            cout << "Name " << name << "\nAge " << age << "\nWeight " << weight << endl
                 << endl;
        }
};

class Point
{
    private:             
        int X;
        int Y;
    public:

        int GetX(){          //геттер
            return X;
        }

        void SetX(int valueX){   //сеттер
            X = valueX;
        }

        void Print(){
            cout << "X = " << X << "\tY = " << Y << endl
                 << endl;
        }
};

int
main()
{
    Point a;
    a.SetX(5);
    a.Print();

    return 0;
}