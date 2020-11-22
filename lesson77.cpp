#include <iostream>
#include <string>
using namespace std;

/*
*   Что такое конкатенация строк
*/

int main()
{
    // //в стиле СИ
    // char result[255]{};
    // char str1[6] = "Hello"; //массив из 6 т.к. букв 5 + '\0'
    // char str2[6] = "World";

    // cout << str1 << endl;
    // strcat(result, str1);    //конкатенация строк в СИ
    // strcat(result, str2);
    // cout << result << endl;

    // в стиле С++

    string str1 = "gardener";
    string str2 = "Jon";
    string str3 = "Jonsan";
    string result;
    result = "Sername: " + str3 + "\t|" + "\tName: " + str2 + "\t|" + "\tPost: " + str1;
    cout << result << endl;
}