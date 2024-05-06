#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getNumber();
/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(double min, double max);
/**
* @breef Табулирует функцию x(y) и выводит в виде столбца
* @param minValue - минимальное значение диапазона
* @param maxValue - максимальное значение диапазона
* @param step - значение шага функции
*/
void printTabFunction(double minValue, double maxValue, double step);
/**
* @breef - Проверка правильности введённого шага
* @param step - значение шага функции
*/
void checkStep(double step);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    cout << "Enter min and max values of range: " << endl;
    double minValue = getNumber();
    double maxValue = getNumber();
    checkRange(minValue, maxValue);
    cout << "Enter step of range = ";
    double step = getNumber();
    checkStep(step);
    printTabFunction(minValue, maxValue, step);
}
double getNumber()
{
    double number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Incorrect input";
        abort();
    }
    return number;
}
void checkRange(double min, double max)
{
    if (min > max)
    {
        cout << "Wrong range entered" << endl;
        abort();
    }
}
void printTabFunction(double minValue, double maxValue, double step)
{
    cout << setw(10) << "x" << setw(10) << "y" << endl;
    for (double i = minValue; i < maxValue + step; i = i + step) {
        double a = i + pow(i, 1 / 2) + pow(i, 1 / 3) - 2.5;
        cout << setw(10) << i << setw(10) << a << endl;
    }
}
void checkStep(double step)
{
    if (step <= 0)
    {
        cout << "Incorrect step!!!" << endl;
        abort();
    }
}