#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10; // Размер массива
    string cities[SIZE]; // Массив для хранения названий городов

    cout << "Введите названия 10 городов:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Город " << (i + 1) << ": ";
        getline(cin, cities[i]);
    }

    int count = 0; // Счетчик городов без буквы 'р'

    for (int i = 0; i < SIZE; ++i) {
        bool hasR = false; // Флаг наличия буквы 'р'

        for (char c : cities[i]) {
            if (c == 'r' || c == 'R') { 
                hasR = true;
                break; 
            }
        }

        if (!hasR) {
            count++; // Увеличиваем счетчик, если буквы 'р' нет
        }
    }

    cout << "Количество городов без буквы 'р': " << count << endl;

    return 0;
}
