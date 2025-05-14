#include <iostream>
#include <fstream> //для работы с файлами
#include <vector> //для динам массива
#include <sstream> //для работы со строками (потоками)
using namespace std;
void writeToFile(const string& filename, const vector<char>& data) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }
    outFile.write(data.data(), data.size());
    outFile.close();
}

vector<char> readFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return {};
    }

    // Получаем размер файла
    inFile.seekg(0, ios::end);
    size_t size = inFile.tellg();
    inFile.seekg(0, ios::beg);

    // Чтение данных из файла
    vector<char> data(size);
    inFile.read(data.data(), size);
    inFile.close();

    return data;
}

void convertToUpper(vector<char>& data) {
    for (char& c : data) {
        if (c >= 'а' && c <= 'я') {
            c = c - ('а' - 'А'); // Преобразуем строчные буквы в заглавные
        }
    }
}

void printData(const vector<char>& data) { //Выводит каждый символ из вектора data на экран.
    for (char c : data) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "data.bin";

    // Ввод символов русского алфавита
    vector<char> inputData;
    string input;

    cout << "Введите символы русского алфавита (строчные): ";
    getline(cin, input);

    // Заполняем вектор данными
    for (char c : input) {
        if (c >= 'а' && c <= 'я') { // Проверка на строчные русские буквы
            inputData.push_back(c);
        }
    }

    // Запись данных в бинарный файл
    writeToFile(filename, inputData);

    // Чтение данных из файла до изменения
    auto originalData = readFromFile(filename);

    // Вывод данных до изменения
    cout << "Данные до изменения: ";
    printData(originalData);

    // Преобразование в заглавные буквы
    convertToUpper(originalData);

    // Запись измененных данных обратно в файл
    writeToFile(filename, originalData);

    // Чтение данных из файла после изменения
    auto modifiedData = readFromFile(filename);

    // Вывод данных после изменения
    cout << "Данные после изменения: ";
    printData(modifiedData);

    return 0;
}
