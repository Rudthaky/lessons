#include <iostream>
#include <string>
using namespace std;

/*
*  Конструктор копирования
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

    ~MyClass()
    {
        cout << "Invoke destructor\t " << data << this << endl;
        delete[] data; //освобождаем динамическую память.
                       //Если бы копирование класса было реализовано
                       //по данной логике:
                       //this->data = other.data;
                       //то при копировании, мы получили бы точную копию
                       //other. С сылкой на туже динамически выделеную память.
                       //Это привело бы к тому, что при вызове деструктора
                       //мы два раза запросили бы очистеть одну и туже область памяти,
                       //что привело бы к ошибке работой с памятью.
                       //В реализации:
                       //this->data = new int[other.Size];
                       //мы создаем объект в новой области памяти, а потом копируем
                       //в этот объек данные из other массива.
    }
};

void Foo(MyClass value)
{
    cout << "Invoke function Foo" << endl;
}

int main()
{
    MyClass a(1);
    MyClass b(a);
    return 0;
}
