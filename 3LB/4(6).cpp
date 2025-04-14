
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string str1, str2;

    cout << "Введите первую строку (Str1): ";
    getline(cin, str1);
    cout << "Введите вторую строку (Str2): ";
    getline(cin, str2);

    // Создаем карту для хранения количества вхождений символов во второй строке
    unordered_map<char, int> charCount;

    // Подсчитываем количество вхождений каждого символа 
    for (char ch : str2) {
        if (ch != ' ') { // Игнорируем пробелы
            charCount[ch]++;
        }
    }

    // Проверяем каждый символ из первой строки на наличие во второй строке
    for (char ch : str1) {
        if (charCount.find(ch) != charCount.end()) {
            cout << "'" << ch << "' встречается " << charCount[ch] << " раз(а) в Str2." << endl;
        }
        else {
            cout << "'" << ch << "' не встречается в Str2." << endl;
        }
    }

    return 0;
}
