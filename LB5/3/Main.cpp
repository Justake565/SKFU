#include <iostream>
#include "Vector3D.h" 

using namespace std;

void menu() {
    cout << "Menu:" << endl;
    cout << "1. Создать вектор" << endl;
    cout << "2. Сложить два вектора" << endl;
    cout << "3. Вычесть два вектора" << endl;
    cout << "4. Вычислить скалярное произведение" << endl;
    cout << "5. Вычислить длину вектора" << endl;
    cout << "6. Вычислить косинус угла между векторами" << endl;
    cout << "0. Выход" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Vector3D vector1(0, 0, 0, 0, 0, 0);
    Vector3D vector2(0, 0, 0, 0, 0, 0);

    int choice;

    do {
        menu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double x1, y1, z1, x2, y2, z2;
            cout << "Введите координаты первого конца вектора (x1 y1 z1): ";
            cin >> x1 >> y1 >> z1;
            cout << "Введите координаты второго конца вектора (x2 y2 z2): ";
            cin >> x2 >> y2 >> z2;
            vector1 = Vector3D(x1, y1, z1, x2, y2, z2);
            vector1.print();
            break;
        }
        case 2: {
            double x1, y1, z1, x2, y2, z2;
            cout << "Введите координаты первого конца второго вектора (x1 y1 z1): ";
            cin >> x1 >> y1 >> z1;
            cout << "Введите координаты второго конца второго вектора (x2 y2 z2): ";
            cin >> x2 >> y2 >> z2;
            vector2 = Vector3D(x1, y1, z1, x2, y2, z2);
            Vector3D sum = vector1 + vector2;
            sum.print();
            break;
        }
        case 3: {
            double x1, y1, z1, x2, y2, z2;
            cout << "Введите координаты первого конца второго вектора (x1 y1 z1): ";
            cin >> x1 >> y1 >> z1;
            cout << "Введите координаты второго конца второго вектора (x2 y2 z2): ";
            cin >> x2 >> y2 >> z2;
            vector2 = Vector3D(x1, y1, z1, x2, y2, z2);
            Vector3D difference = vector1 - vector2;
            difference.print();
            break;
        }
        case 4: {
            double dotProd = vector1.dotProduct(vector2);
            cout << "Скалярное произведение: " << dotProd << endl;
            break;
        }
        case 5: {
            double len = vector1.length();
            cout << "Длина первого вектора: " << len << endl;
            break;
        }
        case 6: {
            double cosAngle = vector1.cosineAngle(vector2);
            cout << "Косинус угла между векторами: " << cosAngle << endl;
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
