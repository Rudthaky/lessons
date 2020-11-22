#include <iostream>
#include <string>
using namespace std;

/*
* Написать Шаблонную функцию, которая меняет местами значения 2-х
* переменных с помощью ссылок
*/

template<typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


int main()
{
    string var1 = "Привет!";
    string var2 = "Пока";

    cout << "var1\t" << var1 << endl;
    cout << "var2\t" << var2 << endl;

    cout << "Swap" << endl;

    Swap(var1, var2);

    cout << "var1\t" << var1 << endl;
    cout << "var2\t" << var2 << endl;
}