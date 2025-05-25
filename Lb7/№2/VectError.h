#pragma once
#ifndef _VECT_ERROR_
#define _VECT_ERROR_

#include <iostream>

#define DEBUG

class VectError {
public:
    VectError() {}
    virtual void ErrMsg() const {
        std::cerr << "Ошибка с объектом Vect.\n";
    }
    void Continue() const {
#ifdef DEBUG
        std::cerr << "Отладка: программа продолжается.\n";
#else
        throw;
#endif
    }
};

class VectRangeErr : public VectError {
public:
    VectRangeErr(int _min, int _max, int _actual) :
        min(_min), max(_max), actual(_actual) {
    }

    void ErrMsg() const override {
        std::cerr << "Ошибка индекса: ";
        std::cerr << "возможный диапазон: " << min << " - " << max << ", ";
        std::cerr << "фактический индекс: " << actual << std::endl;
        Continue();
    }

private:
    int min, max;
    int actual;
};

class VectPopErr : public VectError {
public:
    void ErrMsg() const override {
        std::cerr << "Ошибка pop\n";
        Continue();
    }
};

#endif /* _VECT_ERROR_ */
