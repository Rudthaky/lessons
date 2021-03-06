#include <iostream>
#include <string>

using namespace std;

/*
* Дружественные  классы
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
    }
    friend Human;                   //дружественный класс, нарушение инкапсуляции
private:
    int weight;
    string color;
};

int main()
{
    Apple apple(134, "green");

    Human human;
    human.TakeApple(apple);

    return 0;
}

//Реализация дружественного метода
void Human::TakeApple(Apple &apple)
{
    cout << "Take Apple "
         << "weight = " << apple.weight << "\tcolor = " << apple.color << endl;
}