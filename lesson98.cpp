#include <iostream>
#include <string>

using namespace std;

/**
 * Наследование в ООП
 * 
 */

class Human
{
public:
    string GetName() //NOTE Гетер - получает имя
    {
        return name;
    }

    void SetName(string name) //NOTE сетер - задает имя
    {
        this->name = name;
    }

private:
    string name;
};

class Student : public Human //NOTE пример наследования от класса человек
{
public:
    string group;
    void Learn()
    {
        cout << "I`m study" << endl
             << endl;
    }
};

class ExtramuralStudent : public Student //NOTE наследование от класса студент
{
public:
    void Learn()
    {
        cout << "I visit the university "
             << "less often than the average student."
             << endl
             << endl;
    }
};

class Professor : public Human
{
public:
    string subject;
};

int main()
{
    Student st;
    st.SetName("Ofigelov Figel Figelich");
    cout << st.GetName() << endl;
    st.Learn();

    ExtramuralStudent extraSt;
    extraSt.SetName("Belayshov Vadim Kuzmich");
    cout << extraSt.GetName() << endl;
    extraSt.Learn();

    return 0;
}
