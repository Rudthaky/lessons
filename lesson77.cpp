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

class CoffeeGrinder
{
    private:

    bool CheckVoltage()     //пример инкапсуляции
    {                       //данный метод скрыт от пользователя
        return random()%2;  //и пользователь не знает о том, что "Кофемашина"
    }                       //измеряет "напряжение сети", после которого возвращает результат.
                            //Пользователь только видит последствия проведенного метода
                            //либо "Кофемашина" работает ("VjuHHHH"), либо сигнализирует ошибку
                            //("Beep Beep")

    public:

    void Start()
    {
        for (int i = 0; i < 20; i++)            //цикл введен для демонстрации возможных состояний "Кофемашины"
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
    CoffeeGrinder a;
    a.Start();
    return 0;
}