#include <iostream>
#include <string>

using namespace std;

/*
*   Массив объектов класса
*/

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

private:
    static const int LENGTH = 5;

    Pixel pixels[LENGTH]{
        Pixel(0, 4, 64),
        Pixel(4, 14, 10),
        Pixel(111, 3, 23),
        Pixel(342, 231, 14),
        Pixel(23, 324, 122)};
};

int main()
{
    const int LENGTH = 5;

    //статический массив
    Pixel arr[LENGTH];
    arr[0] = Pixel(22, 33, 12);
    cout << arr[0].GetInfo() << endl;

    int legh = 5;
    //динамический массив
    Pixel *arr1 = new Pixel[legh];
    
    arr1[0] = Pixel(543, 234, 654);
    cout << arr1[0].GetInfo() << endl;

    delete[] arr1;

    return 0;
}