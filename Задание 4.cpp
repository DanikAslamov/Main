﻿#include <iostream>
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
void checkRange(const double min, const double max);
/**
* @breef Табулирует функцию x(y) и выводит в виде столбца
* @param minValue - минимальное значение диапазона
* @param maxValue - максимальное значение диапазона
* @param step - значение шага функции
*/
void printTabFunction(const double minValue, const double maxValue, const double step);
/**
* @breef - Проверка правильности введённого шага
* @param step - значение шага функции
*/
void checkStep(const double step);

/**
 * @brief Проверяет является ли число ООФ (однородной особым функционалом) относительно функции f(x) = x + x^(1/2) + x^(1/3) - 2.5.
 * @param number Проверяемое число.
 * @return true, если число является ООФ, иначе false.
 */
bool isSpecialNumber(const double number);

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
    return 0;
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
void checkRange(const double min, const double max)
{
    if (min > max)
    {
        cout << "Wrong range entered" << endl;
        abort();
    }
}
void printTabFunction(const double minValue, const double maxValue, const double step)
{
    cout << setw(10) << "x" << setw(10) << "y" << endl;
    for (double i = minValue; i < maxValue + step; i = i + step) {
        double a = i + pow(i, 1 / 2) + pow(i, 1 / 3) - 2.5;
        cout << setw(10) << i << setw(10) << a << endl;
    }
}
void checkStep(const double step)
{
    if (step <= 0)
    {
        cout << "Incorrect step!!!" << endl;
        abort();
    }
}

bool isSpecialNumber(const double number)
{
    double result = number + pow(number, 1.0 / 2) + pow(number, 1.0 / 3) - 2.5;

    // Проверка на ООФ
    if (result == number)
    {
        return true;
    }
    else
    {
        return false;
    }
}
