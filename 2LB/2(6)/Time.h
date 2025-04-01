#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(); // Конструктор

    Time(int h, int m, int s); // Конструктор с параметрами

    ~Time();

    int minutesToMidnight() const;

    void add100Minutes();

    string info() const;
};
