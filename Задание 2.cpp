#include <iostream>
#include <stdlib.h>
using namespace std;
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();
/**
* @breef Проверяет число на то, чтобы оно не было равно нулю или меньше нуля
* @return Введённое значение
*/
void checkValue(const double value);
/**
* @breef Считает площадь поверхности шара
* @param a - радиус шара
* @return Площадь поверхности шара
*/
double ballSurface(const double a);
/**
* @breef Считает объём шара
* @param a - длина ребра шара
* @return Объём шара
*/
double ballVolume(const double a);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1
*/
int main()
{
    cout << "Enter radius of ball = " << endl;
    double a = getValue();
    checkValue(a);
    cout << "Surface area of a ball = " << ballSurface(a) << endl;
    cout << "Volume of a ball = " << ballVolume(a) << endl;
    return 0;
}
double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "incorrect value" << endl;
        abort();
    }
    return value;
}
void checkValue(const double value)
{
    if (value <= 0)
    {
        abort();
    }
}
double ballSurface(const double a)
{
    return 4 * 3.14 * pow(a, 2);
}
double ballVolume(const double a)
{
    return (4 / 3) * 3.14 * pow(a, 3);
}
