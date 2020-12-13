#include <iostream>
#include <string>

using namespace std;

/**
 * Чисто виртуальный деструктор 
 */

class A
{
public:
    A()
    {
    }

    virtual ~A() = 0; //Чисто виртуальный деструктор
};

A::~A(){}; //необходимо вынести реализацию деструктора из функции, что бы все корректно компилировалось

class B : public A
{
public:
    B()
    {
    }

    ~B() override
    {
    }
};

int main()
{
    A *bptr = new B;
    delete bptr;

    return 0;
}