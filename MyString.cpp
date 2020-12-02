#include <iostream>

using namespace std;

class MyString
{
public:
    MyString()
    {
        str = nullptr;
    }

    MyString(char *str)
    {
        int length = StrLen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }

    ~MyString()
    {
        delete[] this->str;
    }

    MyString(const MyString &other)
    {
        int length = StrLen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }

    MyString &operator=(const MyString &other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        int length = StrLen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
        return *this;
    }

    MyString operator+(const MyString &other)
    {
        MyString newstr;
        int thisLength = StrLen(this->str);
        int otherLength = StrLen(other.str);

        newstr.str = new char[thisLength + otherLength + 1];

        int i = 0;
        for (; i < thisLength; i++)
        {
            newstr.str[i] = this->str[i];
        }
        for (int j = 0; j < otherLength; j++, i++)
        {
            newstr.str[i] = other.str[j];
        }

        newstr.str[thisLength + otherLength] = '\0';

        return newstr;
    }

    int StrLen(const char *str)
    {
        int counter = 0;
        while (str[counter] != '\0')
        {
            counter++;
        }
        return counter;
    }

    void Print()
    {
        cout << this->str;
    }

private:
    char *str;
};

int main()
{
    MyString str("Hello");
    MyString str2("world");

    MyString result;
    result = str + str2;

    
    return 0;
}