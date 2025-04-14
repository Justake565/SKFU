#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string text;

    // Ввод текста от пользователя
    cout << "Введите строку: ";
    getline(cin, text);

    // Проверяем, достаточно ли символов в строке
    if (text.length() < 7) {
        cout << "Строка должна содержать как минимум 7 символов." << endl;
        return 1;
    }

    // Извлекаем последние 7 символов
    string lastSeven = text.substr(text.length() - 7);

    // Сортируем последние 7 символов
    sort(lastSeven.begin(), lastSeven.end());

    // Заменяем последние 7 символов в исходной строке на отсортированные
    text.replace(text.length() - 7, 7, lastSeven);

    // Выводим результат
    cout << "Результат: " << text << endl;

    return 0;
}
