#include <iostream>
#include <string>
#include "SparseArr.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    // Создаем разреженный массив из double длиной 2 000 000
    SparseArr<double> sal(2000000);

    // Заполняем некоторые элементы
    sal[127649] = 1.1;
    sal[38225] = 1.2;
    sal[2004056] = 1.3; // вне диапазона, будет ошибка
    sal[1999999] = 1.4;

    // Выводим все заполненные элементы
    sal.Show("sal");

    // Вывод конкретного элемента
    std::cout << "sal[38225] = " << sal[38225] << std::endl;

    // Копируем значение из sal[93] в sal[38225]
    sal[38225] = sal[93]; // sal[93] не задан, значит 0 по умолчанию

    std::cout << "После изменения sal:\n";
    sal.Show("sal");

    // Разреженный массив строк длиной 1000
    SparseArr<std::string> sa2(1000);

    sa2[333] = "Nick";
    sa2[222] = "Peter";
    sa2[444] = "Ann";

    sa2.Show("sa2");

    // Копируем значение из sa2[555] в sa2[222]
    sa2[222] = sa2[555]; // sa2[555] не задан, пустая строка

    sa2.Show("sa2");

    return 0;
}
