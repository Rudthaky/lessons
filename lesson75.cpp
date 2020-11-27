#include <iostream>
#include <string>
using namespace std;

/*
*   модификаторы доступа
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
    public:             //модификатор доступа, также 
                        //private: по умолчанию (не возможно 
                        //получить доступ из вне класса за исключением
                        //дружественных классов)
                        //protected:
        int X;
        void Print()    //функцией Print можно обратиться к зоне private
        {               // т.к. все поля находятся в одном классе.
            cout << "Y = " << Y << "\nZ = " << Z << "\nX = " << X << endl;
            Print_Z();
        }

    private:
        int Y;
        int Z;
        void Print_Z()
        {
            cout << "Call Print_Z from private zone = " << Z << endl;
        }
};

int
main()
{
    Point a;
    a.Print();
    return 0;
}