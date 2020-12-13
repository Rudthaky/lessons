#include <iostream>
#include <string>

using namespace std;

/**
 * Абстрактные классы
 * Чисто виртуальные функции
 * virtual
 * override
 */

class Weapon
{
public:
    virtual void Shoot() = 0;
};

class Gun : public Weapon
{
public:
    void Shoot() override
    {
        cout << "BANG!" << endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void Shoot() override
    {
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka : public Weapon
{
public:
    void Shoot() override
    {
        cout << "BADABUM!!!!" << endl;
    }
};

class Knife : public Weapon
{
public:
    void Shoot() override
    {
        cout << "VJUH!!!" << endl;
    }
};

class Player
{
public:
    void Shoot(Weapon *weapon)
    {
        weapon->Shoot();
    }
};

int main()
{
    Gun gun;
    SubmachineGun machineGun;
    Bazooka bazooka;
    Knife knife;

    Player player;
    player.Shoot(&bazooka);
    player.Shoot(&machineGun);
    player.Shoot(&gun);
    player.Shoot(&knife);

    return 0;
}