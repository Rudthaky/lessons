#include <iostream>
using namespace std;

/*
* двумерный динамический массив
*/

int main()
{
    int rows;
    int cols;

    cout << "Enter rows count" << endl;
    cin >> rows;                            

    cout << "Enter cols count" << endl;
    cin >> cols;
    cout << endl
         << endl;

    int **arr = new int *[rows];            //создаем динамический массив указателей

    for (int i = 0; i < rows;i++)
    {
        arr[i] = new int[cols];             //создаем динамический массив 
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    for (int i = 0; i < rows; i++)          //заполняем динамический массив данными
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }

    for (int i = 0; i < rows; i++)          //выводим данные динамического массива
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";      //если &arr[i][j] - выведутся адреса массива данных
        }
        cout << endl;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    for (int i = 0; i < rows; i++)          //Удаляем динамические массивы с данными
    {
        delete[] arr[i];
    }

 delete[] arr;                              //удаляем динамический массив указателей на 
                                            //динамический массив с данными
}