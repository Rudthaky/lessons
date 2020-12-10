#include <iostream>
#include <string>

using namespace std;

/*
*   Агригация и композиция
*/

class Image
{
public:
    void GetImageInfo()
    {
        for (int i = 0; i < LENGTH; i++)
        {
            cout << "#" << i << "\t" << pixels[i].GetInfo() << endl;
        }
    }

    class Pixel
    {
    public:
        Pixel() //требует при создании массива
        {
            r = g = b = 0;
        }

        Pixel(int r, int g, int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        string GetInfo()
        {
            return "Pixel: r = " + to_string(r) +
                   "\tg = " + to_string(g) +
                   "\tb = " + to_string(b);
        }

    private:
        int r;
        int g;
        int b;
    };

private:
    static const int LENGTH = 5;

    Pixel pixels[LENGTH]{
        Pixel(0, 4, 64),
        Pixel(4, 14, 10),
        Pixel(111, 3, 23),
        Pixel(342, 231, 14),
        Pixel(23, 324, 122)};
};

class Cap
{
public:
    string GetColor()
    {
        return color;
    }

private:
    string color = "red";
};

class Model
{
public:
    void InspectModel()
    {
        cout << "Cap is " << cap.GetColor() << endl;
    }

private:
    Cap cap;
};

class Human
{
public:
    void Think()
    {
        brain.Think();
    }

    void InspectTheCap() //пример агрегации
    {
        cout << "My cap " << cap.GetColor() << " color" << endl;
    }

private:
    class Brain //пример компазиции.
                //какой-то объект класса не может существовать
                //без другого объекта класса
    {
    public:
        void Think()
        {
            cout << "I Think!" << endl;
        }
    };
    Brain brain; //компазиция
    Cap cap;     //агрегация (не зависит от класса человек)
};

int main()
{
    Human human;
    human.Think(); //компазиция

    human.InspectTheCap(); //агрегация

    Model model;
    model.InspectModel(); //агрегация
    return 0;
}