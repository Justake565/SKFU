#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Time time1(13, 25, 30);

    cout << "Исходное время: " << time1.info() << endl;

    cout << "Минут до полуночи: " << time1.minutesToMidnight() << endl;

    time1.add100Minutes();

    cout << "Время после добавления 100 минут: " << time1.info() << endl;

    return 0;
}

