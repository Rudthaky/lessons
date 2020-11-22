#include <iostream>
using namespace std;

/*
*   как скопировать динамический массив в с++ 
*/

void FillArray(int* const arr, const int size)      //функция заполнения динамического массива
{                                                   //const - нужен для исключения ошибок приводящих к утечки памяти
    for (int i = 0; i < size; i++)                  //компилятор не позволит как-то изменить передоваемы в функцию 
    {                                               //параметры. int* const arr - не позволит изменить 
        arr[i] = rand() % 10;                       //размерность динамического массива, const int size - не
    }                                               //позволит изменить кол-во запалняемых ячеек в массиве.
}

void ShowArray(const int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int size = 10;                                          //размер массива
    int *ferstArray = new int[size];                        //создание динамического массива ferstArray
    int *secondArray = new int[size];                       //создание динамического массива secondArray

    FillArray(ferstArray, size);                            //заполнение массива случайными значениями
    FillArray(secondArray, size);

    cout << "Ferst Array =\t";                  
    ShowArray(ferstArray, size);                            //вывод массива в консоль
    cout << "Second Array =\t";
    ShowArray(secondArray, size);

    delete[] ferstArray;                                    //удаление динамического массива ferstArray

    ferstArray = new int[size];                             //создание динамического массива ferstArray
    for (int i = 0; i < size; i++)
    {
        ferstArray[i] = secondArray[i];                     //копируем по ячейуам данные из secondArray в ferstArray
    }

    cout << "============================="<<endl;
    cout << "Ferst Array =\t";
    ShowArray(ferstArray, size);                            //вывод массива в консоль
    cout << "Second Array =\t";
    ShowArray(secondArray, size);                           //вывод массива в консоль

    delete[] ferstArray;                                    //удаление динамического массива ferstArray 
    delete[] secondArray;                                   //удаление динамического массива secondArray
}