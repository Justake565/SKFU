#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Television {
    string brand;
    float diagonal; // В дюймах
    float price;    // В валюте (например, рубли)

    // Сериализация структуры в бинарный формат
    void writeToFile(ofstream& out) const {
        size_t brandLength = brand.size();
        out.write(reinterpret_cast<const char*>(&brandLength), sizeof(brandLength));
        out.write(brand.c_str(), brandLength);
        out.write(reinterpret_cast<const char*>(&diagonal), sizeof(diagonal));
        out.write(reinterpret_cast<const char*>(&price), sizeof(price));
    }

    // Десериализация структуры из бинарного формата
    void readFromFile(ifstream& in) {
        size_t brandLength;
        in.read(reinterpret_cast<char*>(&brandLength), sizeof(brandLength));
        brand.resize(brandLength);
        in.read(&brand[0], brandLength);
        in.read(reinterpret_cast<char*>(&diagonal), sizeof(diagonal));
        in.read(reinterpret_cast<char*>(&price), sizeof(price));
    }
};

void createBinaryFile(const string& filename) { //Функция для создания бинарного файла
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    
    vector<Television> televisions = {
        {"Samsung", 40.0, 300.0},
        {"LG", 32.0, 400.0},
        {"Samsung", 50.0, 400.0},
        {"Sony", 55.0, 700.0},
        {"Samsung", 28.0, 500.0}
    };

    // Запись телевизоров в бинарный файл
    for (const auto& tv : televisions) {
        tv.writeToFile(outFile); 
    }

    outFile.close();
}

void readBinaryFile(const string& filename) { //Функция для чтения бинарного файла
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }

    Television tv;
    int samsungCount = 0;

    // Чтение телевизоров из бинарного файла
    while (inFile.peek() != EOF) {
        tv.readFromFile(inFile);

        // Проверка условий 
        if (tv.brand == "Samsung" && tv.diagonal > 32.0) {
            samsungCount++;
            cout << "Фирма: " << tv.brand
                << ", Диагональ: " << tv.diagonal
                << ", Стоимость: " << tv.price << endl;
        }
    }

    cout << "Количество телевизоров Samsung с диагональю более 32 дюймов: " << samsungCount << endl;

    inFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "televisions.dat";

    // Создание бинарного файла с данными о телевизорах
    createBinaryFile(filename);

    // Чтение данных из бинарного файла и вывод информации о телевизорах Samsung
    readBinaryFile(filename);

    return 0;
}
