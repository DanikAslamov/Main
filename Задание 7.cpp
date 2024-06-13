

#include <iostream>
using namespace std;

/**
* @brief Заполнение матрицы автоматически
* @param matrix указатель на массив
* @param rows строки
* @param columns столбцым
*/
void ranom(int** matrix, const int rows, const int columns);

/**
* @brief Копирует массив
* @param matrix указатель на массив
* @param rows строки
* @param columns столбцым
* @return возвращает указатель на скопированный массив
*/
int** copyArray(int** matrix, const int rows, const int columns);

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief Подсчет количества столбцов для новой матрицы для задания 2
* @param orig_matrix указатель на массив
* @param rows строки
* @param columns столбцы
* @return size_t количество столбцов
*/
size_t GetNewColumns(int** orig_matrix, const int rows, const int columns);

/**
* @brief Заполнение матрицы вручную
* @param matrix указатель на массив
* @param rows строки
* @param columns столбцым
*/
void manual(int** matrix, const int rows, const int columns);

/**
* @brief Заменить минимальный по модулю элемент каждого столбца нулем
* @param matrix указатель на массив
* @param rows строки
* @param columns столбцым
*/
void operation1(int** matrix, const int rows, const int columns);


/**
* @brief Вставить после каждой нечетной строки первую строку
* @param orig_matrix указатель на массив исходный
* @param m_matrix указатель на массив с вставленными строками
* @param rows строки исходного
* @param columns столбцы исходного
*/
void operation2(int** orig_matrix, int** m_matrix, const int rows, const int columns);

/**
* @brief Выводит матрицу в stdout
* @param matrix указатель на массив
* @param rows строки
* @param columns столбцы
*/
void print(int** matrix, const int rows, const int columns);

/**
* @brief Выделяет память
* @param rows строки
* @param columns столбцы
* @return возвращает ссылку на выделенную память
*/
int** GetNewMatrix(const int rows, const int columns);

/**
* @brief Очищает выделенную память
* @param matix указатель на массив
* @param rows строки
*/
void FreeMatrix(int** matrix, const int rows);

/**
* @brief Считывает число типа int из stdin с проверкой
* @return возвращает считанный объект
*/
int getValue();

/**
* @brief точка входа в программу
* @return 0 (1)
*/
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество строк" << endl;
    int rows = getValue();
    checkPositive(rows);
    cout << "Введите количество столбцов" << endl;
    int columns = getValue();
    checkPositive(columns);
    cout << "Введите режим ввода(1 - ручной, 0 - случайные числа ): " << endl;
    int type = getValue();
    int** matrix_orig = GetNewMatrix(rows, columns);
    switch (type) {
    case 0:
        ranom(matrix_orig, rows, columns);
        break;
    case 1:
        manual(matrix_orig, rows, columns);
        break;
    default:
        cout << "Некорректное заполнение" << endl;
        return 1;
    }
    cout << "Массив: " << endl;
    print(matrix_orig, rows, columns);

    cout << "Задание - Заменить минимальный по модулю элемент каждого столбца нулем." << endl;
    int** matrix1 = copyArray(matrix_orig, rows, columns);
    operation1(matrix1, rows, columns);
    print(matrix1, rows, columns);
    FreeMatrix(matrix1, rows);


    cout << "Вставить после каждой нечетной строки первую строку." << endl;
    int** matrix2 = GetNewMatrix(rows * 2, columns); // Создаем новую матрицу с удвоенным количеством строк
    operation2(matrix_orig, matrix2, rows, columns);
    print(matrix2, rows * 2, columns);
    FreeMatrix(matrix2, rows * 2);

    FreeMatrix(matrix_orig, rows);
    return 0;
}

size_t GetNewColumns(int** orig_matrix, const int rows, const int columns) {
    size_t res = 0;
    for (size_t j = 0; j < (size_t)columns; j++) {
        if (orig_matrix[0][j] <= orig_matrix[rows - 1][j]) {
            res++;
        }
    }
    return res;
}

void ranom(int** matrix, const int rows, const int columns) {
    for (size_t i = 0; i < (size_t)rows; i++) {
        for (size_t j = 0; j < (size_t)columns; j++) {
            matrix[i][j] = rand() % (100 - -100 + 1) + -100;
        }
    }
}

void manual(int** matrix, const int rows, const int columns) {
    for (size_t i = 0; i < (size_t)rows; i++) {
        for (size_t j = 0; j < (size_t)columns; j++) {
            cout << "ячейка с индексами -> [" << i << "][" << j << "]=";
            cin >> matrix[i][j];
        }
    }
}

void operation1(int** matrix, const int rows, const int columns) {
    for (size_t j = 0; j < (size_t)columns; j++) {
        int min = abs(matrix[0][j]); // Инициализируем min абсолютным значением первого элемента каждой колонки
        size_t min_i = 0; // Индекс строки с минимальным элементом
        for (size_t i = 0; i < (size_t)rows; i++) {
            if (abs(matrix[i][j]) < min) {
                min = abs(matrix[i][j]);
                min_i = i;
            }
        }
        matrix[min_i][j] = 0; // Заменяем минимальный элемент нулем
    }
}

void operation2(int** orig_matrix, int** m_matrix, const int rows, const int columns) {
    for (size_t i = 0; i < (size_t)rows; ++i) {
        for (size_t j = 0; j < (size_t)columns; ++j) {
            m_matrix[i * 2][j] = orig_matrix[i][j]; // Копируем исходную строку
            if (i % 2 == 1) { // Если строка нечетная
                for (size_t k = 0; k < (size_t)columns; ++k) {
                    m_matrix[i * 2 + 1][k] = orig_matrix[0][k]; // Вставляем первую строку после нечетной строки
                }
            }
        }
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

int** GetNewMatrix(const int rows, const int columns) {
    int** matrix = new int* [rows];
    for (size_t i = 0; i < (size_t)rows; ++i) {
        matrix[i] = new int[columns];
    }
    return matrix;
}

void FreeMatrix(int** matrix, const int rows) {
    for (size_t i = 0; i < (size_t)rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** copyArray(int** matrix, const int rows, const int columns) {
    int** resultArray = GetNewMatrix(rows, columns);
    for (size_t i = 0; i < (size_t)rows; i++)
    {
        for (size_t j = 0; j < (size_t)columns; j++)
        {
            resultArray[i][j] = matrix[i][j];
        }
    }
    return resultArray;
}

void print(int** matrix, const int rows, const int columns) {
    cout << endl;
    for (size_t i = 0; i < (size_t)rows; ++i) {
        for (size_t j = 0; j < (size_t)columns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

