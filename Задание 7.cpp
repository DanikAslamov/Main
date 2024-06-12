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
int** copyArray(int **matrix, const int rows, const int columns);

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief Подсчет количества слобцов для нвоой матрицы для задания 2
* @param orig_matrix указатель на массив
* @param rows строки
* @param columns столбцы
* @return size_t количетсво столбцов
*/
size_t GetNewColums(int** orig_matrix, const int rows, const int columns);

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
void operation1(int** matrix, const int rows, const int columnsm);

/**
* @brief Удалить все столбцы, в которых первый элемент больше последнего
* @param t_matrix указатель на массив исходный
* @param m_matrix указатель на массив с удаленнми столбцами
* @param rows строки исходного
* @param columns столбцы исходного
*/
void operation2(int** t_matrix, int** m_matrix, const int rows, const int columns);

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
void FreeMatrix(int **matrix, const int rows);

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
    cout << "Введите количество строк" << endl;
    int rows= getValue();
    checkPositive(rows);
    cout << "Введите количество столбцов" << endl;
    int columns = getValue();
    checkPositive(columns);
    cout << "Введите режим ввода(1 - ручной, 0 - случайные числа от -100 до 100): " << endl;
    int type = getValue();
    int **matrix_orig = GetNewMatrix(rows, columns);
    switch (type) {
        case 0 : 
            ranom(matrix_orig, rows, columns);
            break;
        case 1 :
            manual(matrix_orig, rows, columns);
            break;
        default :
            cout << "Некорректное заполнениe" << endl;
            return 1;
    }
    cout << "Массив: " << endl;
    print(matrix_orig, rows, columns);
    
    cout << "Задание - Заменить минимальный по модулю элемент каждого столбца нулем." << endl;
    int **matrix1 = copyArray(matrix_orig, rows, columns);
    operation1(matrix1, rows, columns);
    print(matrix1, rows, columns);
    FreeMatrix(matrix1, rows);
    
    cout << "Задание - Удалить все столбцы, в которых первый элемент больше последнего." << endl;
    size_t new_colums = GetNewColums(matrix_orig, rows, columns);
    if (new_colums == 0) {
        cout << "будут удалены все столбцы!" << endl;
    } else {
        int **matrix2 = GetNewMatrix(rows, new_colums);
        operation2(matrix_orig, matrix2, rows, columns);
        print(matrix2, rows, new_colums);
        FreeMatrix(matrix2, rows);
    }

    FreeMatrix(matrix_orig, rows);
    return 0;
}

size_t GetNewColums(int** orig_matrix, const int rows, const int columns) {
    size_t res = 0;
    for (size_t i = 0; i < (size_t)columns; i++) {
        if (orig_matrix[0][i] <= orig_matrix[rows - 1][i]) {
            res++;
        }
    }
    return res;
}

void ranom(int** matrix, const int rows, const int columns) {
    for (size_t i = 0; i < (size_t)rows; i++) {
        for (size_t j = 0; j < (size_t)columns; j++) {
            matrix[i][j] =  rand() % (100 - -100 + 1) + -100;
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
void operation1(int** matrix, const int rows, const int columns) 
{
    int* min_i_j[columns] = { nullptr };
    for (size_t j = 0; j < (size_t)columns; j++) 
    {
        int min = matrix[0][j]; // Инициализируем min первым элементом каждой колонки
        for (size_t i = 0; i < (size_t)rows; i++) 
        {
            if (matrix[i][j] < min) 
            {
                min = matrix[i][j];
                min_i_j[j] = &matrix[i][j];
            }
        }
    }
}

void operation2(int** t_matrix, int** m_matrix, const int rows, const int columns) {
    size_t m_cols = 0;
    for (size_t j = 0; j < (size_t)columns; ++j) {
        if (t_matrix[0][j] <= t_matrix[rows-1][j]) {
            for (size_t i = 0; i < (size_t)rows; ++i) {
                m_matrix[i][m_cols] = t_matrix[i][j];
            }
            m_cols++;
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
        cout<<"Error"<<endl;
        abort();
    }     
}

int** GetNewMatrix(const int rows, const int columns) {
    int** matrix = new int*[rows];
    for (size_t i = 0; i < (size_t)rows; ++i) {
        matrix[i] = new int[columns];
    }
    return matrix;
}

void FreeMatrix(int **matrix, const int rows) {
    for (size_t i = 0; i < (size_t)rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** copyArray(int **matrix, const int rows, const int columns) {
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
    cout<< endl;
    for (size_t i = 0; i < (size_t)rows; ++i) {
        for (size_t j = 0; j < (size_t)columns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}