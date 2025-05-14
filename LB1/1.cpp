Решение:
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
   
    ifstream inputFile("a.txt");
    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл a.txt" << endl;
        return 1;
    }

    double number;
    int positiveCount = 0;
    double positiveSum = 0.0;

    // Читаем числа из файла
    while (inputFile >> number) {
        if (number > 0) {
            positiveCount++;
            positiveSum += number;
        }
    }

    inputFile.close();

    // Выводим результаты
    cout << "Количество положительных элементов: " << positiveCount << endl;
    cout << "Сумма положительных элементов: " << positiveSum << endl;

    return 0;
}
