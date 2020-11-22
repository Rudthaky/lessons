#include <iostream>
using namespace std;

/*  Вычисление факториала
*   Рекурсия
*   N! = N*(N-1)!
*/

int Fact(int number)
{
    if(number == 0)
        return 0;
    if(number == 1)
        return 1;
    
    return number * Fact(number - 1);
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << Fact(5) <<endl;
}