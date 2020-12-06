#include <iostream>

using namespace std;

class MyString
{
public:
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    MyString(const char *str)
    {
        length = StrLen(str);
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
        length = StrLen(other.str);
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

        length = StrLen(other.str);
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

        newstr.length = thisLength + otherLength;

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

    int Length()
    {
        return length;
    }

    bool operator==(const MyString &other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyString &other)
    {
        return !(this->operator==(other));
    }

    char &operator[](int index)
    {
        return this->str[index];
    }

    MyString(MyString &&other)
    {
        this->length = other.length;
        this->str = other.str;

        other.str = nullptr;
    }

    MyString &operator=(MyString &&other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        this->length = other.length;
        this->str = other.str;
        other.str = nullptr;

        return *this;
    }

private:
    char *str;
    int length;
};

int main()
{
    MyString str("Hello");
    MyString str2("world");

    MyString result;
    result = str + str2;
    result.Print();
    cout << endl
         << endl;

    cout << str.Length() << endl;
    cout << str2.Length() << endl;
    cout << result.Length() << endl;

    bool equal = str == str2;

    str.Print();
    cout << endl
         << endl;
    str[0] = 'Q';
    str.Print();
    cout << endl;

    return 0;
}