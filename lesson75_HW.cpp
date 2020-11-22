#include <iostream>
using namespace std;

/*
*   Указатель на строку C++
*/

void strLen(const char *str)
{
    int temp = 0;
    
    for (char i = 0; str[i] != '\0'; i++)
    {
        temp++;
    }
    cout << temp << endl;
}

int main()
{
    char *str = "Hello";
    strLen(str);
}