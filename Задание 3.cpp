#include <iostream>
using namespace std;
/**
* @breef Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();
/**
* @breef Возводит в квадрат, если число положительно, иначе возводит в степень 4
* @param a - Число
* @return Возвращает результат
*/
double checkCondition(const double a);
/**
* @breef - главная функция программы
* @return - возвращает 0, если функция выполнена верно, иначе 1
*/
int main() {
    cout << "Enter three real numbers: " << endl;
    double a = getValue();
    double b = getValue();
    double c = getValue();
    cout << "Square if the number is positive, else fourth power:" << endl;
    cout << a << "      ";
    cout << checkCondition(a) << endl;
    cout << b << "      ";
    cout << checkCondition(b) << endl;
    cout << c << "      ";
    cout << checkCondition(c) << endl;
    return 0;
}

double checkCondition(const double a) {
    if (a >= 0)
    {
        return pow(a, 2);
    }
    else
    {
        return pow(a, 4);
    }
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cout << "incorrect value" << endl;
        abort();
    }
    return value;
}
