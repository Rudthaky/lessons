#include <iostream>
#include <string>

using namespace std;

/*
*   Указатель на функцию
*/

//тип функции(*имя указателя)(спецификация параметров);

/*
*   Указатель на функцию может быть использован 
*   В ситуациях, когда мы незнаем какие данные
*   нам могут передавать.
*   К примеру, в нашу функцию передают данные из сервера и БД
*   И мы не знаем кто и когда запросит нашу функцию для
*   вывода данных (сервер или БД)
*/


//функции которые будут передавать нашей функции данные
string GetDataFromWebServer()
{
    return "Data From Web Server";
}
string GetDataFromBD()
{
    return "Data From BD";
}
string GetDataFromAstral()
{
    return "Data From Astral";
}

//наша функция обработки переданных данных (вывод)
void ShowInfo(string (*foo)())
{
    cout << foo() << endl;
}

int main()
{
    ShowInfo(GetDataFromBD);
    ShowInfo(GetDataFromWebServer);
    ShowInfo(GetDataFromAstral);
}