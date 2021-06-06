#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * ebum
 */


class PC
{
public:

    enum PCState
{
    OFF,
    ON,
    SLEEP
};

    PCState GetState() { return State; }
    void SetState(PCState State) { this->State = State; }

private:
    PCState State;
};

int main()
{
    PC pc;
    pc.SetState(PC::PCState::ON);

    if (pc.GetState() == PC::PCState::ON)
    {
        cout << "PC work!!!" << endl;
    }

    switch (pc.GetState())
    {
    case PC::PCState::OFF:
        cout << "PC OFF" << endl;
        break;
    case PC::PCState::ON:
        cout << "PC Work!!!" << endl;
        break;
    case PC::PCState::SLEEP:
        cout << "PC Sleep" << endl;
        break;
    }

    return 0;
}