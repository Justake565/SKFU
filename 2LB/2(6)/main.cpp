#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Time time1(13, 25, 30);

    // Выводим информацию об объекте
    cout << "Исходное время: " << time1.info() << endl;

    // Определяем количество минут до полуночи
    cout << "Минут до полуночи: " << time1.minutesToMidnight() << endl;

    // Увеличиваем время на 100 минут
    time1.add100Minutes();

    cout << "Время после добавления 100 минут: " << time1.info() << endl;

    return 0;
}

