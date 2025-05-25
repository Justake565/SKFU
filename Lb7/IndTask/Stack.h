#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
class Stack {
private:
    vector<T> elements; // Используем vector для хранения элементов

public:
    Stack(); // Конструктор по умолчанию

    void push(const T& value); // Добавить элемент в стек
    void pop(); // Удалить верхний элемент
    T top() const; // Получить верхний элемент
    bool isEmpty() const; // Проверка, пуст ли стек
    size_t size() const; // Получить количество элементов в стеке
};

#include "Stack.cpp" // Включаем реализацию методов

#endif 

