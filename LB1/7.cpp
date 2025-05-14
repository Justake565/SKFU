#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void createMatricesFile(const string& filename, int k, int m, int n) { //Создает текстовый файл matrices.txt 
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    // Генерация случайных матриц
    for (int i = 0; i < k; ++i) {
        outFile << m << " " << n << "\n"; // Запись размерности матрицы
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < n; ++l) {
                int value = rand() % 20 - 10; // Случайные значения от -10 до 9
                outFile << value << " ";
            }
            outFile << "\n";
        }
    }

    outFile.close();
}

vector<vector<vector<int>>> readMatrices(const string& filename, int& k, int& m, int& n) {//Считывает количество матриц и их размерности из файла
    ifstream inFile(filename); //затем считывает сами матрицы и сохраняет их в вектор.
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return {};
    }

    inFile >> k; // Чтение количества матриц
    inFile >> m >> n; // Чтение размерности матриц

    vector<vector<vector<int>>> matrices(k, vector<vector<int>>(m, vector<int>(n)));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < n; ++l) {
                inFile >> matrices[i][j][l];
            }
        }
    }

    inFile.close();
    return matrices;
}

void writeMatricesToFile(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream outFile(filename); //Записывает измененные матрицы в новый файл
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    for (const auto& matrix : matrices) {
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                outFile << element << " ";
            }
            outFile << "\n";
        }
    }

    outFile.close();
}

vector<vector<vector<int>>> processMatrices(vector<vector<vector<int>>>& matrices) {
    vector<vector<vector<int>>> evenSumMatrices; // Обрабатывает матрицы, вычисляет сумму положительных четных элементов и заменяет матрицы с четной суммой на единичные.

    for (auto& matrix : matrices) {
        int sum = 0;

        // Вычисление суммы положительных четных элементов
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                if (element > 0 && element % 2 == 0) {
                    sum += element;
                }
            }
        }

        if (sum % 2 == 0 && sum > 0) { // Если сумма четная и больше нуля
            evenSumMatrices.push_back(matrix); // Сохраняем матрицу с четной суммой
            // Заменяем матрицу на единичную
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    matrix[i][j] = (i == j) ? 1 : 0; // Единичная матрица
                }
            }
        }
    }

    return evenSumMatrices;
}

void printMatrices(const vector<vector<vector<int>>>& matrices) {
    for (const auto& matrix : matrices) {
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                cout << element << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string inputFilename = "matrices.txt";
    const string outputFilename = "processed_matrices.txt";

    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    // Создаем файл с матрицами
    createMatricesFile(inputFilename, 3, 3, 3); 

    int k, m, n;
    auto matrices = readMatrices(inputFilename, k, m, n);

    cout << "Содержимое файла " << inputFilename << ":\n";
    printMatrices(matrices);

    auto evenSumMatrices = processMatrices(matrices);

    writeMatricesToFile(outputFilename, matrices); // Запись измененных матриц в файл

    cout << "Содержимое файла " << outputFilename << ":\n";
    printMatrices(matrices); // Печать измененных матриц

    cout << "Матрицы с четной суммой:\n";
    printMatrices(evenSumMatrices); // Печать матриц с четной суммой

    return 0;
}

