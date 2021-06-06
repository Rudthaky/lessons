#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * создание собственных исключений
 */

class MyException : public logic_error
{
    public:
        MyException(char* msg, int dataState) : logic_error(msg)
        {
            this->dataState = dataState;
        }
        int GetDataState() { return dataState; }

    private:
        int dataState;
};

void Foo(int value)
{
    if (value < 0)
    {
        throw logic_error("Namber < 0 !!!"); //NOTE кидаем исключение
    }

    if (value == 1)
    {
        throw MyException("Exception namber", value);
    }
    cout << "variable = " << value << endl;
}

int main()
{
    try
    {
        Foo(1); //NOTE если вункция не выполняет условие if поподаем в иключение
    }
    catch (MyException &ex) //NOTE обрабатываем исключение, тип throw и ex должны совпадать
    {
        cout << "We catch " << ex.what() << endl;
        cout << "Value is = " << ex.GetDataState() << endl;
    }

    return 0;
} 