#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * обработка исключений throw
 */
void Foo(int value)
{
    if (value < 0)
    {
        throw logic_error("Namber < 0 !!!"); //NOTE кидаем исключение
        /**
         * Если сообщение об ошибке важно, использовать std::exception напрямую 
         * не вариант. В этом случае вы можете использовать либо std::logic_error 
         * или же std::runtime_error, которые наследуют std::exception и у них 
         * есть конструкторы, принимающие строковый аргумент
         */
    }
    cout << "variable = " << value << endl;
}

int main()
{
    try
    {
        Foo(-55); //NOTE если вункция не выполняет условие if поподаем в иключение
    }
    catch (const logic_error &ex) //NOTE обрабатываем исключение, тип throw и ex должны совпадать
    {
        cout << "We catch " << ex.what() << endl;
    }
    return 0;
}