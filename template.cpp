#include <iostream>
using namespace std;

/*Шаблоны функций*/

/* так же можно использовать вместо
* Typenme, можно использовать class*/
template <typename T1, typename T2>
void Sum(T1 a, T2 b)
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Sum(8,"Параметр");
}