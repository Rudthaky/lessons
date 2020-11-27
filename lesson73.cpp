#include <iostream>
#include <string>
using namespace std;

/*
*   Что такое класс
*   Что такое объект класса
*/

class Human             //class - пользовательский тип данных
{
    public:             //модификатор доступа
        int age;        //поле класса         
        int weight;
        string name;
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

    cout << firstHuman.name << "\tage = " << 
    firstHuman.age << "\tweight = " << firstHuman.weight << endl;

    Human secondHuman;
    secondHuman.age = 18;
    secondHuman.name = "Petrov Petr Petrovich";
    secondHuman.weight = 65;
    cout << secondHuman.name << "\tage = " << 
    secondHuman.age << "\tweight = " << secondHuman.weight << endl;

    return 0;
}