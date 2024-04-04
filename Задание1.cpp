#include <iostream>
using namespace std;
/**
* @breef - функция, производящая вычисление результата
* param x - число х
* param y - число y
*/
void getResult(double x, double y);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    const double x = 0.335;
    const double y = 0.025;
    getResult(x, y);
    return 1;
}

void getResult(double x, double y)
{
    cout << "A=" << 1+x+(pow(x,2)/2)+(pow(x,3)/3)+(pow(x,4)/4) << endl;
    cout << "B=" << x*(sin(pow(x,3))+pow(cos(y), 2)) << endl;
}