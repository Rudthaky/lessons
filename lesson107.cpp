#include <iostream>
#include <string>

using namespace std;

/**
 * Делегирующий конструктор
 */

class Human
{
public:
    Human(string Name)
    {
        this->Name = Name;
        this->Age = 0;
        this->Weight = 0;
    }

    Human(string Name, int Age) : Human(Name) //NOTE делегирующий конструктор, использует поля Name делегирующее ему конструктором Human(Name)
    {
        this->Age = Age;
    }

    Human(string Name, int Age, int Weight) : Human(Name, Age) //NOTE делегирующий конструктор,
    //использует поля Name и поле Age делегирующее ему конструктором Human(Name, Age)
    {
        this->Weight = Weight;
    }

    void Print()
    {
        cout << "Name = " << Name << "\tAge = " << Age << "\tWeight = " << Weight << endl;
    }

    string Name;
    int Age;
    int Weight;
};
//NOTE Данный способ удобен при описании множества конструкторов, включающих в себя одинаковые поля.
//При этом логика внутри конструктора может быть разная.
//Так же, данный способ удобен при изменнении, какой либо из переменных
//Например: this->Name = "Agent " + Name;

int main()
{
    Human h("Vasiliy", 30, 70);
    h.Print();
    return 0;
}