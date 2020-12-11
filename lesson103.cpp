#include <iostream>
#include <string>

using namespace std;

/**
 * Полиморфизм
 * Виртуальные функции
 * virtual
 * override
 */

class Gun
{
public:
    virtual void Shoot()
    {
        cout << "BANG!" << endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void Shoot() override //NOTE  override - для проверки компилятором, что мы
                          //не напутали с сигнатурой метода Shoot, который хотим перопределить
    {
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka : public Gun
{
public:
    void Shoot() override 
    {
        cout << "BADABUM!!!!" << endl;
    }
};

class Player
{
public:
    void Shoot(Gun *gun)
    {
        gun->Shoot();
    }
};

int main()
{
    Gun gun;                   //создаем объект класса Gun
    SubmachineGun machineGun;  //создаем объект класса SubmachineGun
    Gun *weapon = &machineGun; //определяем ссылку на объект класса SubmachineGun
                               // указателю на класс Gun
                               //т.к. наш метод переопределен, мы увидим
                               //"BANG! BANG! BANG!".
                               //Если не использовать ключевое слово virtual в классе Gun
                               //то м увидим "BANG!" т.к. наши методоы будут разные и указатель
                               //явно указывает на метод в классе Gun, а не на SubmachineGun.
                               //В этой ситуации полиморфизма нет, но при использовании virtual в классе Gun
                               //мы можем испльзуя указатель на базовый класс, менять поведение наследников.(полиморфизм)

    //weapon->Shoot();
    Bazooka bazooka;

    Player player;
    player.Shoot(&bazooka);
    player.Shoot(&machineGun);
    player.Shoot(&gun);

    return 0;
}