#include "Stack.h"

// Конструктор по умолчанию
template <typename T>
Stack<T>::Stack() = default;

// Добавить элемент в стек
template <typename T>
void Stack<T>::push(const T& value) {
    try {
        elements.push_back(value); // Добавляем элемент в стек
    }
    catch (const bad_alloc& e) {
        throw runtime_error("Ошибка выделения памяти при добавлении элемента в стек");
    }
}

// Удалить верхний элемент
template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Ошибка: стек пуст. Невозможно удалить элемент.");
    }
    elements.pop_back(); // Удаляем верхний элемент
}

// Получить верхний элемент
template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw underflow_error("Ошибка: стек пуст. Невозможно получить верхний элемент.");
    }
    return elements.back(); // Возвращаем верхний элемент
}

// Проверка, пуст ли стек
template <typename T>
bool Stack<T>::isEmpty() const {
    return elements.empty(); // Проверяем, пуст ли стек
}

// Получить количество элементов в стеке
template <typename T>
size_t Stack<T>::size() const {
    return elements.size(); // Возвращаем количество элементов в стеке
}
