#include <iostream>
#include <string>

using namespace std;

/**
 * Шаблоны классов
 */

class Point
{
private:
    int x;
    int y;
    int z;

public:
    Point()
    {
        x = y = z = 0;
    }
    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

template <typename T1, typename T2>
class TemplareClass
{
public:
    TemplareClass(T1 value, T2 value2)
    {
        this->value = value;
        this->value2 = value2;
    }

    void DataTypeSize()
    {
        cout << "Value " << sizeof(value) << endl;
        cout << "Value2 " << sizeof(value2) << endl;
    }

private: 
    T1 value;
    T2 value2;
};

int main()
{
    int a = 2;
    Point p;
    TemplareClass<int, Point> c(a, p);

    c.DataTypeSize();


    return 0;
}