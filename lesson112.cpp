#include <iostream>
#include <string>

using namespace std;

/**
 * С++ множественное наследование одинаковые методы.
 */

class Car
{
public:
    void Use() //NOTE одинаковый метод
    {
        cout << "I`m Drive!" << endl;
    }
};

class Airplain
{
public:
    void Use() //NOTE одинаковый метод
    {
        cout << "I`m Fly!" << endl;
    }
};

class FlyingCar : public Car, public Airplain //NOTE множественное наследование
{
public:
};

int main()
{
    FlyingCar fc;
    ((Car)fc).Use(); //NOTE приведение к типу Car
    cout << endl
         << endl;
    ((Airplain)fc).Use(); //NOTE приведение к типу Airplain
    cout << endl
         << endl;

    return 0;
}