#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string text;
    cout << "Введите текст: ";
    getline(cin, text); // Считываем весь текст

    int countA = 0; // Счетчик слов на "А"
    int countMalo = 0; // Счетчик слов "мало"

    string word;
    stringstream ss(text); // Используем stringstream для разделения на слова

    while (ss >> word) { // Извлекаем слова из текста
        // Проверка на слова, начинающиеся на "А" или "а"
        if (word.length() > 0 && (word[0] == 'A' || word[0] == 'a')) {
            countA++;
        }

        // Проверка на слова "мало" или "Мало"
        if (word == "few" || word == "Few") {
            countMalo++;
        }
    }

    // Замена "доллар" на "рубль"
    size_t pos = 0;
    while ((pos = text.find("dollar", pos)) != string::npos) {
        text.replace(pos, 6, "ruble"); // Заменяем "доллар" (6 символов) на "рубль"
        pos += 5; // Переходим к следующему символу после "рубль"
    }

    // Вывод результатов
    cout << "Количество слов, начинающихся на 'А': " << countA << endl;
    cout << "Количество слов 'мало' или 'Мало': " << countMalo << endl;
    cout << "Измененный текст: " << text << endl;

    return 0;
}

