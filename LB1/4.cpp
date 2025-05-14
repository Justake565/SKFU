#include <iostream>
#include <fstream> //для работы с файлами
#include <vector> //для хранения чисел
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файл для чтения
    ifstream inputFile("numbers.txt");
    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл numbers.txt" << endl;
        return 1;
    }

    vector<int> numbers;
    int number;

    // Читаем числа из файла
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    int sum = 0;
    int count = 0;

    // Вычисляем сумму и количество положительных чисел с индексами кратными трем
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 3 == 0 && numbers[i] > 0) {
            sum += numbers[i];
            count++;
        }
    }

    // Вычисляем среднее значение
    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Среднее значение положительных чисел с индексами, кратными трем: " << average << endl;
    }
    else {
        cout << "Нет положительных чисел с индексами, кратными трем." << endl;
    }

    return 0;
}

