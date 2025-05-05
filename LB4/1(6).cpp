#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10; 
    string cities[SIZE]; 

    cout << "Введите названия 10 городов:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Город " << (i + 1) << ": ";
        getline(cin, cities[i]);
    }

    int countt = 0;  
    for (const string& city : cities) {
        if (!city.empty() && city[0] == 'A') {
            countt++;
        }
    }

    cout << "Количество городов, начинающихся на букву 'А': " << countt << endl;

    return 0;
}
