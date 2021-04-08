#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * обработка исключений try catch
 */


int main()
{
    string path = "./execute/lesson119.txt";

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "Trying to open a file" << endl;
        fin.open(path);
        cout << "File is open successful!" << endl;
    }
    catch(const ifstream::failure& ex)
    {
        cout << ex.what() << endl;
        cout << ex.code() << endl;
        cout << "Error open file" << endl;
    }

    fin.close();

    return 0;
}