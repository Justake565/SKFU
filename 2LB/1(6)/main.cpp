#include <iostream>
#include "Time.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int minutes, seconds;
    cout << "Введите время: " << endl;
    cin >> minutes >> seconds;
    TimeConverter* problem = new TimeConverter(minutes, seconds); //Создание объекта класса
    problem->console();
    delete problem;
    return 0;
};

