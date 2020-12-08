#include <iostream>
#include <string>

using namespace std;

/*
* id generator
*/

class Apple; //должны указать, т.к. класс Human еще не знает о существовании
             // класса Apple
             //      |
             //      |
             //      V

class Human
{
public:
    void TakeApple(Apple &apple); //"Прототип" метода
};

class Apple
{
public:
    static int Count;

    Apple(int weight, string color) //определяем конструктор класса Apple
    {
        this->weight = weight;
        this->color = color;
        Count++;
        id = Count;
    }
    friend Human; //дружественный класс, нарушение инкапсуляции

    int GetId()
    {
        return id;
    }

private:
    int weight;
    string color;
    int id;
};

int Apple::Count = 0;

int main()
{
    Apple apple1(123, "red");
    Apple apple2(32, "green");
    Apple apple3(122, "Yellow");

    cout << apple1.GetId() << endl;
    cout << apple2.GetId() << endl;
    cout << apple3.GetId() << endl;


    return 0;
}

//Реализация дружественного метода
void Human::TakeApple(Apple &apple)
{
    cout << "Take Apple "
         << "weight = " << apple.weight << "\tcolor = " << apple.color << endl;
}
