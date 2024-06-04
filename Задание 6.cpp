// 6 lab
#include <iostream>
#include <random>
using namespace std;

/**
* @brief заполняет массив случаными числами
* @param arr указатель на массив
* @param size размерность массива
*/
void randFill(int* arr, const int size);

/**
* @brief заполняет массив вручную через stdin
* @param arr указатель на массив
* @param size размерность массива
*/
void manualFill(int* arr, const int size);

/**
* @brief вычисляет сумму нечетных элементов масива
* @param arr указатель на массив
* @param size размерность массива
*/
int sumOddIndx(const int* arr, const int size);

/**
* @brief вычисляет количество элементов больших А
* @param arr указатель на массив
* @param size размерность массива
* @param A параметр
*/
int countMoreA(const int* arr, const int size, const int A);

/**
* @brief делит все нечетные элементы на первый элемент массива, не значащий нулю
* @param arr указатель на массив
* @param size размерность массива
*/
void divideTo00(int* arr, const int size);

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief Считывает число типа int из stdin с проверкой
* @return возвращает считанный объект
*/
int getValue();

/**
* @brief точка входа в программу
* @return 0 (или 1 при ошибке)
*/
int main() {
    cout << "Введите n: ";
    int n = getValue();
    checkPositive(n);
    cout << "Введите A: ";
    int A = getValue();
    cout << "Введите режим (1 - ручной ввод, 0 - случайные числа от -20 до 10): ";
    int mode = getValue();

    int* arr = new int[n]();

    switch (mode) {
        case 0 :
            randFill(arr, n);
            break;
        case 1 :
            manualFill(arr, n);
            break;
        default :
            cout << "Некорректный режим заполнения!" << endl;
            return 1;
    }

    cout << "Массив заполнен: " << endl;
    for (size_t i = 0; i < n; ++i) {
        cout << "[" << i << "]=" << *(arr + i) << endl;
    }

    cout << endl << "1) Найти сумму элементов, имеющих нечетные индексы.\nОтвет: "<< sumOddIndx(arr, n) << endl;
    cout << "2)Подсчитать количество элементов массива, значения которых больше заданного числа А и кратных 5.\nОтвет: "<< countMoreA(arr, n, A) << endl;
    cout << "3)Разделить все элементы массива с четными номерами на первый элемент (первый элемент отличен от 0)\nОтвет: " << endl;
    divideTo00(arr, n);
    for (size_t i = 0; i < n; ++i) {
        cout << "[" << i << "]=" << *(arr + i) << endl;
    }
    
    delete[] arr;
    return 0;
}

void randFill(int* arr, const int size) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> distribution(-10, 20);

    for (size_t i = 0; i < size; ++i) {
        *(arr + i) = distribution(gen);
    }
}
void manualFill(int* arr, const int size) {
    for (size_t i = 0; i < size; ++i) {
        cout << "arr[" << i << "] --> ";
        cin >> *(arr + i);
        cout << endl;
    }
}

int sumOddIndx(const int* arr, const int size) {
    int res = 0;
    for (size_t i = 1; i < size; i += 2) {
        res += *(arr + i);
    }
    return res;
}

int countMoreA(const int* arr, const int size, const int A) {
    int res = 0;
    for (size_t i = 0; i < size; ++i) {
        if (*(arr + i) > A && *(arr + i) % 5 == 0) {
            res++;
        }
    }
    return res;
}

void divideTo00(int* arr, const int size) {
    if (arr[0] == 0) {
        cout << "arr[0] = 0, невозможно выполнить пункт 3!" << endl;
        return;
    }

    for (size_t i = 1; i < size; i += 2) {
        *(arr + i) /= arr[0];
    }
}

int getValue() {
    int value;
    cin >> value;
    if (cin.fail()) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

void checkPositive(const int value) {     
    if (value <= 0) {     
        cout << "Error" << endl;
        abort();
    }     
}