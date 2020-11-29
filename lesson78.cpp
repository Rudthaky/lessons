#include <iostream>
#include <string>
using namespace std;

/*
*   конструктор класса с параметрами
*   по умолчанию
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
    Point(int valueX, int valueY)       //конструктор
    {   
        X = valueX;                     //теперь компилятор не будет создавать
        Y = valueY;                     //контрутор по умолчанию
    }                                   //При попытки созтать класс без параметров 
                                        //компилятор выдаст ошибку
                                        //no default constructor exists for class "Point"

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

class CoffeeGrinder
{
    private:

    bool CheckVoltage()
    {
        return random()%2;
    }

    public:

    void Start()
    {
        for (int i = 0; i < 20; i++)
        {
            if(CheckVoltage()){
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
    Point a(5, 44);
    a.Print();

    Point b(66, 33);
    b.Print();

    return 0;
}