#include <iostream>

using namespace std;

/*Указатели и массивы. Арефметика указателей*/

int main()
{
    const int SIZE = 5;
    int arr[SIZE]{4,44,56,34,5};    //arr - это указатель на первый элемент массива
    int *pArr = arr;                //pArr- так же указатель на первый элемент массива

    for(int i = 0; i < SIZE; i++)
    {
        cout << arr[i] <<endl;
    }

    cout << "================================="<<endl;
    cout << "arr\t" << arr << endl;
    cout << "pArr\t" << pArr <<endl;
    cout << "================================="<<endl;


    for(int i = 0; i < SIZE; i++)
    {
        cout << pArr[i] <<endl;
    }
    //записи эквивалентны
    for(int i = 0; i < SIZE; i++)
    {
        cout << *(pArr+i) <<endl;   //указатель на первый элемент массива
    }
    cout << "================================="<<endl;
    cout << *(pArr+2) << endl;
    cout << "================================="<<endl;
}