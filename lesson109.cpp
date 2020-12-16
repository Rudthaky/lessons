#include <iostream>
#include <string>

using namespace std;

/**
 * Множественное наследование
 */

class Car
{
public:
    string str = "Car class";
    void Drive()
    {
        cout << "I`m Drive!" << endl;
    }
};

class Airplain
{
public:
    string str1 = "Airplain class";
    void Fly()
    {
        cout << "I`m Fly!" << endl;
    }
};

class FlyingCar : public Car, public Airplain//NOTE множественное наследование
{
    public:
};

int main()
{
    FlyingCar fc;
    fc.Drive();
    fc.Fly();

    Car *ptrC = &fc;

    Airplain *ptrA = &fc;

    return 0;
}