#include <iostream>
#include <string>

using namespace std;

/*
*   Определение методов вне класса
*   Вынесение функции из/в класса
*/

class MyClass
{
private:
    /* data */
public:
    MyClass(/* args */);
    ~MyClass();

    void printMessage();
};

MyClass::MyClass(/* args */)
{
}

MyClass::~MyClass()
{
}

void MyClass::printMessage()
{
    cout << "Hello!" << endl;
}

int main()
{
    MyClass a;
    a.printMessage();
    return 0;
}