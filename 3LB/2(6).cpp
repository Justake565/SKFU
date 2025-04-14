#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string text;

    cout << "Введите текст: ";
    getline(cin, text); // Считываем весь текст

    string result; // Строка для хранения результата
    bool lastWasSpace = false; // Флаг для отслеживания пробелов

    for (char ch : text) { // Проходим по каждому символу в исходном тексте
        if (ch == '#') {
            continue; // Пропускаем символы '#'
        }
        if (ch == '.') {
            if (lastWasSpace) {
                // Если последний символ был пробелом, не добавляем его
                result.pop_back(); // Убираем последний пробел из результата
            }
            result += ch; // Добавляем точку
            lastWasSpace = false; // Сбрасываем флаг
        }
        else {
            result += ch; // Добавляем текущий символ в результат
            lastWasSpace = (ch == ' '); // Устанавливаем флаг, если текущий символ пробел
        }
    }

    // Выводим результат
    cout << "Измененный текст: " << result << endl;

    return 0;
}
