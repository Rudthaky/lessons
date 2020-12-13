#include <iostream>
#include <string>

using namespace std;

/**
 * Виртуальный деструктор
 */

class A
{
public:
    A()
    {
        cout << "constructor A" << endl;
    }

    virtual ~A() //NOTE без vitrual будет утечка памяти при выделении
                 //динамической памяти
    {
        cout << "destructor A" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "constructor B" << endl;
    }

    ~B() override
    {
        cout << "destructor B" << endl;
    }
};

int main()
{
    A *bptr = new B; //NOTE выделяем динамическую память
                     //если диструктор не virtual
                     //удалиться указатель на объект класса А
                     //но не на объект класса B и произойдет утечка памяти!
                     //Напиминаю, что указатель на базовый класс может
                     //хранить в себе указатели на наследников базового класса
    delete bptr;

    return 0;
}