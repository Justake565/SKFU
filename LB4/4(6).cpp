#include <iostream>
#include <string>
#include <algorithm> // Для sort
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10; 
    string cities[SIZE]; 
    string filteredCities[SIZE]; // Массив для хранения отфильтрованных городов
    int filteredCount = 0; // Счетчик отфильтрованных городов

    
    cout << "Введите названия 10 городов:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Город " << (i + 1) << ": ";
        getline(cin, cities[i]);
    }

    
    for (int i = 0; i < SIZE; ++i) {
        if (!cities[i].empty() && cities[i].back() == 'v') { // Проверяем, что город не пустой и заканчивается на 'в'
            filteredCities[filteredCount] = cities[i]; // Копируем город в новый массив
            filteredCount++; // Увеличиваем счетчик
        }
    }

    
    sort(filteredCities, filteredCities + filteredCount); // Упорядочивание второго списка по алфавиту

  
    cout << "Города, заканчивающиеся на 'в', отсортированные по алфавиту:" << endl;
    for (int i = 0; i < filteredCount; ++i) {
        cout << filteredCities[i] << endl;
    }

    return 0;
}
