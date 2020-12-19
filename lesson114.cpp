#include <iostream>
#include <string>

using namespace std;

/**
 * ромбовидное насделование
 * Виртуальное наследование
 */

class Component
{
public:
    Component(string companyName)
    {
        cout << "constructor Component " << endl;
        this->companyName = companyName;
    }
    string companyName;
};

class GPU : public Component
{
public:
    GPU(string companyName) : Component(companyName)
    {
        cout << " constructor GPU " << endl;
    }
};

class Memory : public Component
{
public:
    Memory(string companyName) : Component(companyName)
    {
        cout << " constructor Memory " << endl;
    }
};

class GraphicCard : public GPU, public Memory
{
public:
    GraphicCard(string CPUCompanyName, string MemoryCompanyName) : GPU(CPUCompanyName), Memory(MemoryCompanyName)
    {
        cout << "constructor GraphicCard " << endl;
    }
};

//----------------------------------------------------
// ромбовидное насделование

class Character
{
public:
    Character()
    {
        cout << "constructor Character" << endl;
    }
    int HP;
};

class Orc : public virtual Character //NOTE виртуальное наследование для
{                                    //того, чтобы 2 раза не наследовать
public:                              //class Character. Таким образом в классе
    Orc()                            //Orc_Warrior будет всего одно поле HP
    {
        cout << "constructor Orc" << endl;
    }
};

class Warrior : public virtual Character
{
public:
    Warrior()
    {
        cout << "constructor Warrior" << endl;
    }
};

class Orc_Warrior : public Orc, public Warrior
{
public:
    Orc_Warrior()
    {
        cout << "constructor Orc_Warrior" << endl;
    }
};

int main()
{
    GraphicCard gc("AMD", "Samsung");
    Orc_Warrior ow;

    return 0;
}


/**Схема ромбовидного наследования
 *          -------------
 *          |    HP     |
 *          -------------
 *          /           \
 *  -------------   ---------------
 *  |   Orc     |   |   Warrior   |
 *  -------------   ---------------
 *          \           /
 *          -------------
 *          |Orc_Warrior|
 *          -------------
 */