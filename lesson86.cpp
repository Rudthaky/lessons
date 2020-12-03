#include <iostream>
#include <string>
using namespace std;

/*
*  перегрузка инкремента и декремента
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

class MyClass
{
    int *data;
    int Size;

public: //Не забывать писать модификатор доступа!!!
    MyClass(int size)
    {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        cout << "Invoke constructor\t" << data << this << endl;
    }

    //конструктор копирования. При работе с динамической памятью он кретичен
    MyClass(const MyClass &other)
    {
        this->Size = other.Size;             //копируем Size из одного класса в другой
        this->data = new int[other.Size];    //выделяем динамическую память под новый масив
        for (int i = 0; i < other.Size; i++) //копируем данные из other в data
        {
            this->data[i] = other.data[i];
        }
        cout << "Invoke copy constructor\t" << data << this << endl;
    }

    MyClass &operator=(const MyClass &other) //прегрузка оператора =
    {
        cout << "Invoke operator =\t" << this << endl;

        if (this->data = nullptr) //проверка на нулевой указатель, если память уже осовобождена
        {                         //то повторное освобождение памяти не происходит
            delete[] this->data;
        }

        this->data = new int[other.Size];    //создаем новый динамический массив данных
                                             //с размером, таким же как у массива other
        for (int i = 0; i < other.Size; i++) //копируем в массив данные
        {
            this->data[i] = other.data[i];
        }
        return *this; //возвращаем текущие значения, это необходимо для
    }                 //случая a=b=c. Именно для этого мы берм ссылку на этот объект
                      //MyClass&

    ~MyClass()
    {
        cout << "Invoke destructor\t " << data << this << endl;
        delete[] data; //освобождаем динамическую память.
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
        cout << this << "constructor" << endl;
    }

    Point(int X, int Y) //перегрузка
    {
        this->X = X;
        this->Y = Y;
    }

    bool operator==(const Point &other)
    {
        return this->X == other.X && this->Y == other.Y;
    }

    bool operator!=(const Point &other)
    {
        return !(this->X == other.X && this->Y == other.Y);
    }

    Point operator+(const Point &other)
    {
        Point temp;
        temp.X = this->X + other.X;
        temp.Y = this->Y + other.Y;
        return temp;
    }

    //~~~~~~~~~~~~~~~~~~ниже приер реализации  ~~~~~~~~~~~~~~~~~~~
    //------------------------------------------------------------
    Point &operator++()
    {
        this->X++;
        this->Y += 1;

        return *this;
    }

    Point &operator++(int value)
    {
        Point temp(*this);
        this->X++;
        this->Y++;
        return temp;
    }

    Point &operator--()
    {
        this->X--;
        this->Y -= 1;

        return *this;
    }

    Point &operator--(int value)
    {
        Point temp(*this);
        this->X--;
        this->Y--;
        return temp;
    }

    //------------------------------------------------------------

    int GetX()
    { //геттер
        return this->X;
    }

    void SetX(int X)
    { //сеттер
        this->X = X;
    }

    void Print()
    {
        cout << "X = " << X << "\tY = " << Y << endl
             << endl;
    }
};

int main()
{
    Point a(1, 1);
    ++a;
    a++;
    --a;

    Point b = a;

    return 0;
}
