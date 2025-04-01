#include "Time.h"
using namespace std;
Time::Time() : hours(0), minutes(0), seconds(0) { // иницилиз. время нулями
    cout << "Объект Time создан (по умолчанию)." << endl;
}


Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) { // Конструктор с параметрами
    cout << "Объект Time создан с параметрами." << endl;
}

Time::~Time() { 
    cout << "Объект Time уничтожен." << endl;
}

int Time::minutesToMidnight() const { // Метод 1: Определить количество минут до полуночи
    return (23 - hours) * 60 + (59 - minutes);
}

void Time::add100Minutes() { // Метод 2: Увеличить время на 100 минут
    minutes += 100;
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24; // Это нужно, чтобы часы не превышали 23
    }
}

string Time::info() const { // Метод для формирования строки информации об объекте
    stringstream ss;
    ss << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    return ss.str();
}
