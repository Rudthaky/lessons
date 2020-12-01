#include <iostream>
#include <string>
using namespace std;

/*
*  перегрузка оператора присваевания
*/

class MyClass
{
    int *data;
    int Size;

public: //Не забывать писать модификатор доступа!!!
    MyClass(int size)
    {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        cout << "Invoke constructor\t" << data << this << endl;
    }

    //конструктор копирования. При работе с динамической памятью он кретичен
    MyClass(const MyClass &other)
    {
        this->Size = other.Size;             //копируем Size из одного класса в другой
        this->data = new int[other.Size];    //выделяем динамическую память под новый масив
        for (int i = 0; i < other.Size; i++) //копируем данные из other в data
        {
            this->data[i] = other.data[i];
        }
        cout << "Invoke copy constructor\t" << data << this << endl;
    }

    MyClass& operator=(const MyClass &other)            //прегрузка оператора =
    {
        cout << "Invoke operator =\t" << this << endl;

        if (this->data = nullptr)                       //проверка на нулевой указатель, если память уже осовобождена
        {                                               //то повторное освобождение памяти не происходит
            delete[] this->data;
        }

        this->data = new int[other.Size];               //создаем новый динамический массив данных
                                                        //с размером, таким же как у массива other
        for (int i = 0; i < other.Size; i++)            //копируем в массив данные
        {
            this->data[i] = other.data[i];
        }
        return *this;                                   //возвращаем текущие значения, это необходимо для 
    }                                                   //случая a=b=c. Именно для этого мы берм ссылку на этот объект
                                                        //MyClass&

    ~MyClass()
    {
        cout << "Invoke destructor\t " << data << this << endl;
        delete[] data; //освобождаем динамическую память.
    }
};

void Foo(MyClass value)
{
    cout << "Invoke function Foo" << endl;
}

int main()
{
    MyClass a(10);
    MyClass b(2);
    MyClass c(5);
    
    a = b = c;

    return 0;
}
