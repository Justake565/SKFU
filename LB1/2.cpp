#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile1("a1.txt");
    ifstream inputFile2("a2.txt");

    if (!inputFile1) {
        cerr << "Ошибка: не удалось открыть файл a1.txt" << endl;
        return 1;
    }

    if (!inputFile2) {
        cerr << "Ошибка: не удалось открыть файл a2.txt" << endl;
        return 1;
    }

    double number;
    int zeroCount = 0;

    // Подсчет нулевых элементов в первом файле
    while (inputFile1 >> number) {
        if (number == 0.0) {
            zeroCount++;
        }
    }

    // Подсчет нулевых элементов во втором файле
    while (inputFile2 >> number) {
        if (number == 0.0) {
            zeroCount++;
        }
    }

    inputFile1.close();
    inputFile2.close();

    // Выводим результат
    cout << "Количество нулевых элементов в двух файлах: " << zeroCount << endl;

    return 0;
}

