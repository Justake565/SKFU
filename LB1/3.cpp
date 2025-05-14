#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Открываем исходный файл для чтения
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл input.txt" << endl;
        return 1;
    }
    else {
        cout << "Файл input.txt успешно открыт." << endl;
    }

    // Открываем выходной файл для записи
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Ошибка: не удалось создать файл output.txt" << endl;
        return 1;
    }
    else {
        cout << "Файл output.txt успешно создан." << endl;
    }

    string line;

    // Читаем файл построчно
    while (getline(inputFile, line)) {
        // Заменяем цифры на '*'
        for (char& ch : line) {
            if (isdigit(ch)) {
                ch = '*';
            }
        }
        // Записываем изменённую строку в выходной файл
        outputFile << line << endl;
    }

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    cout << "Заменены все цифры на '*' и сохранены в output.txt." << endl;

    return 0;
}
