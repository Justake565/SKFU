#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
void createFile(const string& filename) { //Эта функция создает файл с именем, переданным в качестве аргумента filename.
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    outFile << "3.14\n";
    outFile << "-2.3\n";
    outFile << "3.7\n";
    outFile << "-4.1\n";
    outFile << "5.0\n";

    outFile.close();
}

vector<double> readFile(const string& filename) { //Эта функция открывает файл для чтения
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return {};
    }

    vector<double> numbers;
    double number;

    while (inFile >> number) {
        numbers.push_back(number);
    }

    inFile.close();
    return numbers;
}

void calculateAndWriteResults(const vector<double>& numbers, const string& outputFilename) { //принимает вектор чисел для записи
    if (numbers.empty()) {
        cerr << "Нет данных для обработки." << endl;
        return;
    }

    double sum = 0.0;
    double product = 1.0;

    for (double num : numbers) {
        sum += num;
        product *= num;
    }

    double modulusSum = abs(sum);
    double squareProduct = product * product;

    ofstream outFile(outputFilename);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << outputFilename << endl;
        return;
    }

    outFile << "Модуль суммы: " << modulusSum << "\n";
    outFile << "Квадрат произведения: " << squareProduct << "\n";

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string inputFilename = "numbers.txt";
    const string outputFilename = "results.txt";

    // Создаем файл с данными
    createFile(inputFilename);

    // Читаем данные из файла
    auto numbers = readFile(inputFilename);

    // Вычисляем результаты и записываем их в новый файл
    calculateAndWriteResults(numbers, outputFilename);

    cout << "Результаты сохранены в файл " << outputFilename << endl;

    return 0;
}
