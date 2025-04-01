#include <iostream>
#include "Time.h"
using namespace std;
TimeConverter::TimeConverter(int minutes, int seconds) : minutes(minutes), seconds(seconds) {}

void TimeConverter::console() { //вызывает метод для вывода результата
    cout << "Полученный результат: " << half_TimeConverter(minutes, seconds) << endl;
}

double TimeConverter::half_TimeConverter(int minutes, int seconds) {
    return (minutes * 60 + seconds) / 2.0; // Возвращаем половину времени в секундах
}



