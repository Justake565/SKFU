#include "MyStrings.h"
using namespace std;
void showMenu() {
    cout << "1. Создать SymbString\n";
    cout << "2. Создать BinString\n";
    cout << "3. Показать объект\n";
    cout << "4. Удалить объект\n";
    cout << "5. Выход\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    BaseString* obj = nullptr;
    int choice;

    while (true) {
        showMenu();
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string id, value;
            cout << "Введите идентификатор и значение для SymbString: ";
            cin >> id >> value;
            obj = Factory::createSymbString(id, value);
            break;
        }
        case 2: {
            string id;
            int value;
            cout << "Введите идентификатор и значение для BinString: ";
            cin >> id >> value;
            obj = Factory::createBinString(id, value);
            break;
        }
        case 3:
            if (obj) {
                obj->show();
            }
            else {
                cout << "Объект не создан.\n";
            }
            break;
        case 4:
            if (obj) {
                Factory::deleteObject(obj);
                obj = nullptr;
                cout << "Объект удален.\n";
            }
            else {
                cout << "Объект не создан.\n";
            }
            break;
        case 5:
            if (obj) {
                Factory::deleteObject(obj);
            }
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
