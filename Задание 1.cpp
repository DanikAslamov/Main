#include <iostream>
using namespace std;
/**
* @breef - функция, производящая вычисление результата
* param x - число х
* param y - число y
* @return - возвращает результат 
*/
double getResultA(const double x, const double y);
/**
* @breef - функция, производящая вычисление результата
* param x - число х
* param y - число y
* @return - возвращает результат
*/
double getResultB(const double x, const double y);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    const double x = 0.335;
    const double y = 0.025;
    cout << "A=" << getResultA(x, y) << endl;
    cout << "B=" << getResultB(x, y) << endl;
    return 0;
}

double getResultA(const double x, const double y)
{
    return (1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4));

}
double getResultB(const double x, const double y)
{
    return (x * (sin(pow(x, 3)) + pow(cos(y), 2)));
}
