#include <iostream>
#include <string>

using namespace std;

/**
 * интерфейсы
 */

class Ibicycle
{
public:
    void virtual TwistTheWheel() = 0;
    void virtual Ride() = 0;
};

class SimpleBicycle : public Ibicycle
{
public:
    void TwistTheWheel() override
    {
        cout << "Method TwistTheWheel() SimpleBicycle" << endl
             << endl;
    }
    void Ride() override
    {
        cout << "Method Ride() SimpleBicycle" << endl
             << endl;
    }
};

class SportBicycle : public Ibicycle
{
public:
    void TwistTheWheel() override
    {
        cout << "Method TwistTheWheel() SportBicycle" << endl
             << endl;
    }
    void Ride() override
    {
        cout << "Method Ride() SportBicycle" << endl
             << endl;
    }
};

class Human
{
public:
    void RideOn(Ibicycle &bicycle)
    {
        cout << "turn the steering wheel" << endl;
        bicycle.TwistTheWheel();
        cout << endl
             << "Go, Go, Go!!!" << endl;
        bicycle.Ride();
    }
};

int main()
{
    SimpleBicycle sb;
    SportBicycle sportB;

    Human h;
    h.RideOn(sportB);
   
    return 0;
}