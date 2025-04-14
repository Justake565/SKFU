#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string text;

    cout << "Введите текст: ";
    getline(cin, text); 

    string result; // Строка для хранения результата
    bool lastWasSpace = false; //  для отслеживания пробелов

    for (char ch : text) { 
        if (ch == '#') {
            continue; // Пропускаем символы '#'
        }
        if (ch == '.') {
            if (lastWasSpace) {
                result.pop_back(); // Убираем последний пробел из результата
            }
            result += ch; // Добавляем точку
            lastWasSpace = false; // Сбрасываем флаг
        }
        else {
            result += ch; 
            lastWasSpace = (ch == ' '); // Устанавливаем флаг, если текущий символ пробел
        }
    }

    cout << "Измененный текст: " << result << endl;

    return 0;
}
