#include <iostream>
#include <string>

using namespace std;

/**
 * Порядок вызова конструкторов при множественном наследовании.
 * Порядок вызова деструкторов при множественном наследовании.
 */

class Car
{
public:
    Car()
    {
        cout << "CONSTRUCTOR CAR" << endl;
    }
    ~Car()
    {
        cout << "DESTRUCTOR CAR" << endl;
    }
    void Drive()
    {
        cout << "I`m Drive!" << endl;
    }
};

class Airplain
{
public:
    Airplain()
    {
        cout << "CONSTRUCTOR AIRPLAIN" << endl;
    }
    ~Airplain()
    {
        cout << "DESTRUCTOR AIRPLAIN" << endl;
    }
    void Fly()
    {
        cout << "I`m Fly!" << endl;
    }
};

class FlyingCar : public Car, public Airplain //NOTE порядок наследования
{
public:
    FlyingCar()
    {
        cout << "CONSTRUCTOR FLYINGCAR" << endl;
    }
    ~FlyingCar()
    {
        cout << "DESTRUCTOR FLYINGCAR" << endl;
    }
};

int main()
{
    FlyingCar fc;

    return 0;
}