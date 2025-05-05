#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 20; 
    string peaks[SIZE]; 

    // Ввод названий горных вершин
    cout << "Введите названия 20 горных вершин:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Вершина " << (i + 1) << ": ";
        getline(cin, peaks[i]);
    }

    // Инициализация переменной st с первым названием
    string st = peaks[0];

    
    for (int i = 1; i < SIZE; ++i) {
        if (peaks[i].length() < st.length()) {
            st = peaks[i];
        }
    }

    
    cout << "Самое короткое название горной вершины: " << st << endl;

    return 0;
}
