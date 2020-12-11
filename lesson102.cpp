#include <iostream>
#include <string>

using namespace std;

/**
 * Вызов конструктора базового класса из конструктора 
 * класса-наследника.
 */

class A
{
public:
    A()
    {
        cout << "Noll message" << endl;
    }

    A(string msg)
    {
        this->msg = msg;
    }

    void PrintMsg()
    {
        cout << msg << endl;
    }

private:
    string msg;
};

class B : public A
{
public:
    B() : A("My string in B") //NOTE явно указываем конструктор
    {
        cout << "Show constructor B" << endl;
    }
};

int main()
{
    B b;
    b.PrintMsg();
    return 0;
}