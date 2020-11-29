#include <iostream>
#include <string>
using namespace std;

/*
*  Деструктор класса
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

    void SetX(int valueX)
    { //сеттер
        X = valueX;
    }

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

//~~~~~~~~~~~~~~ пример с деструктором ~~~~~~~~~~~~~~~~~~~~~~~~~
class MyClass
{
    int *data;

public: //Не забывать писать модификатор доступа!!!
    MyClass(int size)
    {
        data = new int[size]; //если выделяем динамическую память
                              //нам нужно позаботиться о том, чтобы
                              //не происходило утечки памяти
                              //для таких ситуаций можно использовать
                              //деструктор
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        cout << "Object " << data << "\tconstructor" << endl;
    }
    ~MyClass()         //Деструктор может быть только один
    {                  //Деструктор не может принимать параметры!
        delete[] data; //свобождаем динамическую память
        cout << "Object " << data << "\tdestructor" << endl;
    }
};

void Foo()
{
    cout << "Foo works " << endl;
    MyClass a(1);
    cout << "Foo unworks" << endl;
}

int main()
{
    Foo();
    return 0;
}
