#ifndef _VECT_
#define _VECT_

#include <iostream>
#include <string>
#include "VectError.h"

// Template class Vect
template<class T>
class Vect {
public:
    explicit Vect() : first(nullptr), last(nullptr) {}
    explicit Vect(size_t _n, const T& _v = T()) {
        Allocate(_n);
        for (size_t i = 0; i < _n; ++i)
            *(first + i) = _v;
    }
    Vect(const Vect& other) { // конструктор копирования
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        markName = "Копия " + other.markName;
    }

    Vect& operator=(const Vect& other) { // операция присваивания
        if (this == &other) return *this;
        Destroy();
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        return *this;
    }

    ~Vect() { Destroy(); } // деструктор

    void mark(const std::string& name) { markName = name; }
    std::string mark() const { return markName; }
    size_t size() const { return (first == nullptr ? 0 : last - first); }
    T* begin() const { return first; }
    T* end() const { return last; }

    T& operator[](size_t i) {
        if (i < 0 || i >= size())
            throw VectRangeErr(0, size() - 1, i);
        return *(first + i);
    }

    void insert(T* _P, const T& _x) {
        size_t n = size() + 1; // новый размер
        T* new_first = new T[n];
        T* new_last = new_first + n;
        size_t offset = _P - first;
        for (size_t i = 0; i < offset; ++i)
            *(new_first + i) = *(first + i);
        *(new_first + offset) = _x;
        for (size_t i = offset; i < n - 1; ++i)
            *(new_first + i + 1) = *(first + i);
        Destroy();
        first = new_first;
        last = new_last;
    }

    void push_back(const T& _x) {
        if (size() == 0) {
            Allocate(1);
            *first = _x;
        }
        else {
            insert(last, _x);
        }
    }

    void pop_back() {
        if (last == first)
            throw VectPopErr();
        T* p = end() - 1;
        p->~T();
        last--;
    }

    void show() const {
        std::cout << "\n===== Содержание " << markName << " =====\n";
        size_t n = size();
        for (size_t i = 0; i < n; ++i)
            std::cout << *(first + i) << " ";
        std::cout << std::endl;
    }

protected:
    void Allocate(size_t _n) {
        first = new T[_n];
        last = first + _n;
    }

    void Destroy() {
        for (T* p = first; p != last; ++p) p->~T();
        delete[] first;
        first = nullptr;
        last = nullptr;
    }

private:
    T* first; // указатель на 1-й элемент
    T* last;  // указатель на элемент, следующий за последним
    std::string markName;
};

#endif /* _VECT_ */
