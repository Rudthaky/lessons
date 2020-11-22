#include <iostream>
using namespace std;

/* 
*   строки в С++
*   строковый массив в С++ 
*   Таблица символов ASCII
*/

int main()
{
   setlocale(LC_ALL, "ru");
    char string[] = "a";
    cout << string << endl;

    for (int i = 0; i <= 255; i++)
    {
        cout << "code = " << i << "\t"
             << "char = " << (char)i << endl;
    }
}