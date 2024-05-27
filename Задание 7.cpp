// 6 lab
#include <iostream>
#include <random>
using namespace std;


/**
* @brief Заполняет массив случаными числами
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void randFill(int** arr, const int n, const int m);

/**
* @brief Заполняет массив вручную через stdin
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void manualFill(int** arr, const int n, const int m);

/**
* @brief Заменяет все элементы первых трех столбцов на их квадраты
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void repalceThreeColumns(int** arr, const int n, const int m);

/**
* @brief Вставляет после каждой нечетной строки первую строку
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
int** insertFirstRow(int** arr, const int n, const int m);

/**
* @brief Выводит матрицу в stdout
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void printMatrix(int** arr, const int n, const int m);

/**
* @brief Выделяет память под массив
* @param arr указатель на массив
* @param n количество строк
* @param m количество столбцов
*/
void alloc(int ***arr, const int n, const int m);


/**
* @brief Очищает выделенную память под массив
* @param arr указатель на массив
* @param n количество строк
*/
void dealloc(int **arr, const int n);

/**
* @brief Считывает число типа int из stdin с проверкой
* @return возвращает считанный объект
*/
int getValue();

/**
* @brief Копирует массив из шаблона
* @param arr указатель на массив-шаблон
* @param n количество строк
* @param m количество столбцов
* @return возвращает указатель на скопированный массив
*/
int** copyArray(int **arr, const int n, const int m);

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief точка входа в программу
* @return 0 (или 1 при ошибке)
*/
int main() {
    cout << "Введите количество строк" << endl;
    int n = getValue();
    checkPositive(n);
    cout << "Введите количество столбцов" << endl;
    int m = getValue();
    checkPositive(m);
    cout << "Введите режим ввода(1 - ручной, 0 - случайные числа от -100 до 100): " << endl;
    int mode = getValue();

    int **arr;
    alloc(&arr, n, m);

    switch (mode) {
        case 0 : 
            randFill(arr, n, m);
            break;
        case 1 :
            manualFill(arr, n, m);
            break;
        default :
            cout << "Некорректный режим заполнения!" << endl;
            return 1;
    }
    cout << "Массив заполнен: " << endl;
    printMatrix(arr, n, m);
    
    cout << "1) Заменить все элементы первых трех столбцов на их квадраты." << endl;
    int **first_task_arr = copyArray(arr, n, m);
    repalceThreeColumns(first_task_arr, n, m);
    printMatrix(first_task_arr, n, m);
    dealloc(first_task_arr, n);
    
    cout << "2) Вставить после каждой нечетной строки первую строку." << endl;
    int **second_task_arr = insertFirstRow(arr, n, m);
    printMatrix(second_task_arr, (n + (n / 2)), m);
    dealloc(second_task_arr, (n + (n / 2)));

    dealloc(arr, n);
    return 0;
}

void randFill(int** arr, const int n, const int m) {
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> distribution(-100, 100);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            arr[i][j] = distribution(gen);
        }
    }
}

void manualFill(int** arr, const int n, const int m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cout << " [" << i << "][" << j << "]=";
            cin >> arr[i][j];
        }
    }
}

void repalceThreeColumns(int** arr, const int n, const int m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            arr[i][j] *= arr[i][j];
        }
    }
}

int** insertFirstRow(int** arr, const int n, const int m) {
    int **newArr;
    alloc(&newArr, n + (n / 2), m);

    int rowIndex = 0;

    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            for (size_t j = 0; j < m; ++j) {
                newArr[rowIndex][j] = arr[i][j];
            }
            ++rowIndex;
            for (size_t j = 0; j < m; ++j) {
                newArr[rowIndex][j] = arr[0][j];
            }
            ++rowIndex;
        } else {
            for (size_t j = 0; j < m; ++j) {
                newArr[rowIndex][j] = arr[i][j];
            }
            ++rowIndex;
        }
    }

    return newArr;
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
        cout<<"Error"<<endl;
        abort();
    }     
}

int** copyArray(int **arr, const int n, const int m) {
    int** resultArray;
    alloc(&resultArray, n, m);
    for (size_t i = 0; i < n; i++)
    {     
        for (size_t j = 0; j < m; j++)
        {     
            resultArray[i][j] = arr[i][j];
        }     
    }
    return resultArray;
}

void printMatrix(int** arr, const int n, const int m) {
    cout << "-------------------" << endl;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

void alloc(int ***arr, const int n, const int m) {
    *arr = new int*[n];
    for (size_t i = 0; i < n; ++i) {
        (*arr)[i] = new int[m];
    }
}

void dealloc(int **arr, const int n) {
    for (size_t i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}