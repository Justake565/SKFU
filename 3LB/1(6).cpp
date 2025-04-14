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

    int countA = 0; 
    int countMalo = 0; 

    string word;
    stringstream ss(text); // Используем для разделения на слова

    while (ss >> word) { // Извлекаем слова из текста
        // Проверка 
        if (word.length() > 0 && (word[0] == 'A' || word[0] == 'a')) {
            countA++;
        }

        if (word == "few" || word == "Few") {
            countMalo++;
        }
    }

    // Замена "доллар" на "рубль"
    size_t pos = 0;
    while ((pos = text.find("dollar", pos)) != string::npos) {
        text.replace(pos, 6, "ruble"); 
        pos += 5; // Переходим к следующему символу после "рубль"
    }

    
    cout << "Количество слов, начинающихся на 'А': " << countA << endl;
    cout << "Количество слов 'мало' или 'Мало': " << countMalo << endl;
    cout << "Измененный текст: " << text << endl;

    return 0;
}
