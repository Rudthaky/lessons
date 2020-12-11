#include <iostream>
#include <string>

using namespace std;

/**
 * порядок вызова конструктора при наследовани
 * порядок вызова деструктора при наследовании
 */

class A
{
public:
    A()
    {
        cout << "Show constructor A" << endl;
    }

    ~A()
    {
        cout << "Show destructor A" << endl;
    }

};

class B : public A
{
public:
    B()
    {
        cout << "Show constructor B" << endl;
    }

    ~B()
    {
        cout << "Show destructor B" << endl;
    }
};

class C : public B
{
public:
    C()
    {
        cout << "Show constructor C" << endl;
    }

    ~C()
    {
        cout << "Show destructor C" << endl;
    }
};

int main()
{
    C c;
    return 0;
}