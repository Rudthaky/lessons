#include <iostream>
using namespace std;

/*
* Создание динамического массива в оперативной памяти
*/

int main()
{
    int size = 0;
    cout << "Enter array size" << endl
         << endl;
    cin >> size;
    cout << endl
         << endl;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10; //заполнение случайными данными
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t" << arr + i << endl; //вывод значений динамического массива и адреса ячеек массива (арифметика указателей)
    }

    delete[] arr;       //удаление динамического массива
}