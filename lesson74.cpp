#include <iostream>
#include <string>
using namespace std;

/*
*   Методы класса
*   Функции класса
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
    public:
        int X;
        int Y;
        int Z;
};

int
main()
{
    Point a;            //создание преременной "а" типа Point, a - объект класа Point
    a.X = 1;            //передаем в "а", параметр "Х", значение координаты по Х
    a.Y = 3;
    a.Z = 5;

    cout << a.X << " " << a.Y << " " << a.Z << endl;

    Human firstHuman;
    firstHuman.age = 30;
    firstHuman.name = "Ivanov Ivan Ivanovych";
    firstHuman.weight = 100;
    firstHuman.Print();

    Human secondHuman;
    secondHuman.age = 18;
    secondHuman.name = "Petrov Petr Petrovich";
    secondHuman.weight = 65;
    secondHuman.Print();

    return 0;
}