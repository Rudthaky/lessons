#include <iostream>
#include <string>

using namespace std;

/*
*   Наследование в ООП
*/

class Human
{
public:
    string GetName()
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

private:
    string name;
};

class Student : public Human //пример наследования от класса чедовек
{
public:
    string group;
    void Learn()
    {
        cout << "I`m study" << endl
             << endl;
    }
};

class ExtramuralStudent : public Student
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
