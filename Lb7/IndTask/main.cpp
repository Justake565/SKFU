#include "Stack.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    try {
        Stack<int> intStack; // Создаем стек для целых чисел
        intStack.push(10);
        intStack.push(20);
        cout << "Верхний элемент стека: " << intStack.top() << endl; // Должно вывести 20
        intStack.pop();
        cout << "Верхний элемент стека после удаления: " << intStack.top() << endl; // Должно вывести 10

        Stack<double> doubleStack; // Создаем стек для double
        doubleStack.push(3.14);
        doubleStack.push(2.71);
        cout << "Верхний элемент стека double: " << doubleStack.top() << endl; // Должно вывести 2.71

        Stack<string> stringStack; // Создаем стек для строк
        stringStack.push("Hello");
        stringStack.push("World");
        cout << "Верхний элемент стека строк: " << stringStack.top() << endl; // Должно вывести "World"

        // Пробуем удалить все элементы
        stringStack.pop();
        stringStack.pop();

        // Пробуем вызвать pop на пустом стеке
        stringStack.pop(); // Это вызовет исключение
    }
    catch (const exception& e) {
        cerr << "Исключение: " << e.what() << endl; // Обрабатываем исключения
    }

    return 0;
}
