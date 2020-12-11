#include <iostream>
#include <string>

using namespace std;

/**
 * Спецификаторы доступа при наследовании
 */

class A
{
public:
    string msgOne = "Message one"; //NOTE доступно всем

private:
    string msgTwo = "Message Two"; //NOTE доступно только классу А

protected:
    string msgThree = "Message Three"; //NOTE разрешает работать наследнику класса А,
                                       //но не разрешает работать объекту класса наследника
};

class B : public A //NOTE при изменение доступа наследника, наследник будет себя вести в
                   //соответствии с таблицей 1
{
public:
    void PrintMsg()
    {
        cout << msgOne << endl;
        cout << msgThree << endl; //можно обратиться
    }
};

int main()
{
    B b;
    // b.msgOne;    //разрешено
    // b.msgTwo;    //не разрешено
    // b.msgThree;  //не разрешено
    b.PrintMsg();
    return 0;
}

//NOTE Таблица 1
// |--------------------------------------------------------|
// |                |   public  |   private |   protected   |
// |--------------------------------------------------------|
// |public          |           |           |               |
// |наследование    |   public  |   private |   protected   |
// |--------------------------------------------------------|
// |private         |           |           |               |
// |наследование    |   private |   private |   private     |
// |--------------------------------------------------------|
// |protected       |           |           |               |
// |наследование    | protected |   private |   protected   |
// |--------------------------------------------------------|