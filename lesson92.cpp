#include <iostream>
#include <string>

using namespace std;

/*
* Статические поля класса
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
    }
    friend Human; //дружественный класс, нарушение инкапсуляции
private:
    int weight;
    string color;
};

int Apple::Count = 0;

class Comments
{
public:
    static int count_id;
    Comments(string comment)
    {
        this->comment = comment;
        count_id++;
        id_comment = count_id;
    }

    void PrintComment()
    {
        cout << "comment id = " << id_comment << "\tcomment = " << comment << endl
             << endl;
    }

private:
    int id_comment;
    string comment;
};

int Comments::count_id = 0;

int main()
{
    Apple apple(134, "green");
    Apple apple2(150, "Red");
    Apple apple3(200, "Yellow");

    cout << Apple::Count << endl;

    Comments comm("ferst commit");
    Comments comm2("Second commit");
    Comments comm3("3 commit");

    comm.PrintComment();
    comm3.PrintComment();
    comm2.PrintComment();

    int num = 0;
    char a;
    string b;
    while (a != 'q')
    {
        cout << "Write your comment." << endl;
        cin >> b;
        Comments comm(b);
        comm.PrintComment();
        cout << "Enter 'q' to exit or another symbol, to stay" << endl;
        cin >> a;
    }
    return 0;
}

//Реализация дружественного метода
void Human::TakeApple(Apple &apple)
{
    cout << "Take Apple "
         << "weight = " << apple.weight << "\tcolor = " << apple.color << endl;
}
