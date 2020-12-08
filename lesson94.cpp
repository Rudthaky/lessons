#include <iostream>
#include <string>

using namespace std;

/*
* Статические методы
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

    static int GetCount()
    {
        return Count; //только статическое поле
    }

    static void ChangeColor(Apple &apple, string color)
    {
        apple.color = color;
    }

    string PrintColor(Apple &apple)
    {
        return apple.color;
    }

private:
    static int Count;
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

    cout << apple1.PrintColor(apple1) << endl;

    // cout << apple1.GetId() << endl;

    cout << Apple::GetCount() << endl;

    apple1.ChangeColor(apple1, "Green");
    cout << apple1.PrintColor(apple1) << endl;

    return 0;
}

//Реализация дружественного метода
void Human::TakeApple(Apple &apple)
{
    cout << "Take Apple "
         << "weight = " << apple.weight << "\tcolor = " << apple.color << endl;
}
