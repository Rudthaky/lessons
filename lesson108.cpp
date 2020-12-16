#include <iostream>
#include <string>

using namespace std;

/**
 * вызов метода базового класса
 */

class Msg
{
    string msg;

public:
    Msg(string msg)
    {
        this->msg = msg;
    }

    virtual string GetMsg()
    {
        return msg;
    }
};

class BraketsMsg : public Msg
{
public:
    BraketsMsg(string msg) : Msg(msg)
    {
    }
    string GetMsg() override
    {
        return "[" + ::Msg::GetMsg() + "]"; //c++ вызов виртуального метода базового класса.
    }
};

class Printer
{
public:
    void Print(Msg *msg)
    {
        cout << msg->GetMsg() << endl;
    }
};

int main()
{
    BraketsMsg m("Hello!");
    Printer p;
    p.Print(&m);

    return 0;
}