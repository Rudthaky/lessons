#include <iostream>
#include <string>

using namespace std;

/*
*   Вложенный класс
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

private:
    class Pixel
    {
    public:
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
    Image img;
    img.GetImageInfo();
    return 0;
}