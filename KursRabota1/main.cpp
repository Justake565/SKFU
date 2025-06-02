#include <iostream> 
#include "ApartmentExchange.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");  
    system("chcp 1251");           

    ApartmentExchange exchange;  // Создаем объект системы обмена квартирами
    exchange.loadFromFile("requests.txt");  // Загружаем заявки из файла

    int choice;  // Переменная для выбора пользователя

    
    do {
        
        cout << "\nМеню:\n";
        cout << "1. Ввод заявки на обмен\n";
        cout << "2. Поиск подходящего варианта\n";
        cout << "3. Вывод всех заявок\n";
        cout << "4. Сохранить в файл\n";
        cout << "0. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        // Обрабатываем выбор пользователя
        switch (choice) {
        case 1: {  // Добавление новой заявки
            int rooms, floor;
            double area;
            string district;

            
            cout << "Введите данные искомой квартиры (количество комнат, площадь, этаж, район): ";
            cin >> rooms >> area >> floor >> district;
            Apartment desired(rooms, area, floor, district);

            
            cout << "Введите данные имеющейся квартиры (количество комнат, площадь, этаж, район): ";
            cin >> rooms >> area >> floor >> district;
            Apartment offered(rooms, area, floor, district);

            // Создание и добавление заявки
            ExchangeRequest request(desired, offered);
            exchange.addRequest(request);
            break;
        }
        case 2: {  // Поиск совпадений
            int rooms, floor;
            double area;
            string district;

            
            cout << "Введите ваши данные искомой квартиры (количество комнат, площадь, этаж, район): ";
            cin >> rooms >> area >> floor >> district;
            Apartment desired(rooms, area, floor, district);

            
            cout << "Введите ваши данные имеющейся квартиры (количество комнат, площадь, этаж, район): ";
            cin >> rooms >> area >> floor >> district;
            Apartment offered(rooms, area, floor, district);

            // Создание заявки и поиск совпадений
            ExchangeRequest request(desired, offered);
            exchange.findMatch(request);
            break;
        }
        case 3:  // Вывод всех заявок
            exchange.displayRequests();
            break;
        case 4:  // Сохранение в файл
            exchange.saveToFile("requests.txt");
            break;
        case 0:  // Выход из программы
            cout << "Выход...\n";
            break;
        default:  
            cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);  

    return 0;
}
