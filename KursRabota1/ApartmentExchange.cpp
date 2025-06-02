#include "ApartmentExchange.h"

// Добавляет новую заявку в список заявок
void ApartmentExchange::addRequest(const ExchangeRequest& request) {
    requests.push_back(request);  
}

// Ищет совпадение для указанной заявки среди существующих
bool ApartmentExchange::findMatch(const ExchangeRequest& request) {
    auto it = requests.begin();
    while (it != requests.end()) {
        // Проверяем условия совпадения:
        // 1. Количество комнат в желаемой квартире одного пользователя должно совпадать
        //    с количеством комнат в предлагаемой квартире другого
        // 2. Этажи должны совпадать
        // 3. Разница в площади не должна превышать 10%
        if (it->getDesired().getRooms() == request.getOffered().getRooms() &&
            it->getDesired().getFloor() == request.getOffered().getFloor() &&
            abs(it->getDesired().getArea() - request.getOffered().getArea()) <= 0.1 * it->getDesired().getArea()) {

     
            cout << "\n=== Найдено совпадение ===\n";
            cout << "Искомая квартира: " << it->getDesired().getRooms() << " комн., "
                << it->getDesired().getArea() << " кв.м, " << it->getDesired().getFloor()
                << " этаж, район: " << it->getDesired().getDistrict() << "\n";
            cout << "Имеющаяся квартира: " << it->getOffered().getRooms() << " комн., "
                << it->getOffered().getArea() << " кв.м, " << it->getOffered().getFloor()
                << " этаж, район: " << it->getOffered().getDistrict() << "\n";

            // Спрашиваем пользователя, хочет ли он удалить найденную заявку
            cout << "\nУдалить найденную заявку из картотеки? (y/n): ";
            char choice;
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                it = requests.erase(it);  // Удаляем заявку из списка
                cout << "Заявка успешно удалена из картотеки.\n";
                return true;  // Возвращаем true, так как совпадение найдено и обработано
            }
            return false;  // Совпадение найдено, но не обработано (не удалено)
        }
        else {
            ++it;  // Переходим к следующей заявке
        }
    }
    // Если совпадений не найдено, добавляем новую заявку в список
    cout << "Совпадений не найдено. Заявка добавлена в картотеку.\n";
    addRequest(request);
    return false;  // Совпадений не найдено
}

// Удаляет указанную заявку из списка
bool ApartmentExchange::removeRequest(const ExchangeRequest& request) {
    auto it = requests.begin();
    while (it != requests.end()) {
        // Ищем заявку, полностью совпадающую по всем параметрам
        if (it->getDesired().getRooms() == request.getDesired().getRooms() &&
            it->getDesired().getFloor() == request.getDesired().getFloor() &&
            it->getDesired().getDistrict() == request.getDesired().getDistrict() &&
            it->getOffered().getRooms() == request.getOffered().getRooms() &&
            it->getOffered().getFloor() == request.getOffered().getFloor() &&
            it->getOffered().getDistrict() == request.getOffered().getDistrict()) {

            it = requests.erase(it);  // Удаляем найденную заявку
            return true;  
        }
        else {
            ++it;  
        }
    }
    return false;  // Заявка не найдена
}

// Сохраняет все заявки в указанный файл
void ApartmentExchange::saveToFile(const string& filename) const {
    ofstream file(filename);  // Открываем файл для записи
    if (file.is_open()) {
        for (const auto& req : requests) {
            // Записываем данные о желаемой квартире
            file << req.getDesired().getRooms() << ","
                << req.getDesired().getArea() << ","
                << req.getDesired().getFloor() << ","
                << req.getDesired().getDistrict() << "\n"
                // Записываем данные о предлагаемой квартире
                << req.getOffered().getRooms() << ","
                << req.getOffered().getArea() << ","
                << req.getOffered().getFloor() << ","
                << req.getOffered().getDistrict() << "\n";
        }
        file.close();  // Закрываем файл
        cout << "Данные успешно сохранены в файл " << filename << endl;
    }
    else {
        cerr << "Не удалось открыть файл для записи.\n";
    }
}

// Загружает заявки из указанного файла
void ApartmentExchange::loadFromFile(const string& filename) {
    currentFilename = filename;  // Сохраняем имя файла
    ifstream file(filename);     // Открываем файл для чтения
    requests.clear();            // Очищаем текущий список заявок

    if (file.is_open()) {
        while (!file.eof()) {  // Читаем до конца файла
            int rooms, floor;
            double area;
            string district;

            if (file >> rooms) {  // Если успешно прочитали количество комнат
                file.ignore();     // Пропускаем запятую
                file >> area;     // Читаем площадь
                file.ignore();    
                file >> floor;     // Читаем этаж
                file.ignore();    
                getline(file, district);  // Читаем район

                // Создаем объект желаемой квартиры
                Apartment desired;
                desired.setRooms(rooms);
                desired.setArea(area);
                desired.setFloor(floor);
                desired.setDistrict(district);

                // Аналогично читаем данные о предлагаемой квартире
                file >> rooms;
                file.ignore();
                file >> area;
                file.ignore();
                file >> floor;
                file.ignore();
                getline(file, district);

                // Создаем объект предлагаемой квартиры
                Apartment offered;
                offered.setRooms(rooms);
                offered.setArea(area);
                offered.setFloor(floor);
                offered.setDistrict(district);

                // Создаем заявку и добавляем в список
                ExchangeRequest request(desired, offered);
                addRequest(request);
            }
        }
        file.close();  // Закрываем файл
    }
    else {
        cerr << "Не удалось открыть файл для чтения. Будет создан новый файл при сохранении.\n";
    }
}

// Выводит все заявки на экран
void ApartmentExchange::displayRequests() const {
    if (requests.empty()) {  // Если список пуст
        cout << "Картотека пуста.\n";
        return;
    }

    // Проходим по всем заявкам и выводим их данные
    for (const auto& req : requests) {
        cout << "Искомая квартира: " << req.getDesired().getRooms() << " комн., "
            << req.getDesired().getArea() << " кв.м, " << req.getDesired().getFloor()
            << " этаж, район: " << req.getDesired().getDistrict() << "\n";
        cout << "Имеющаяся квартира: " << req.getOffered().getRooms() << " комн., "
            << req.getOffered().getArea() << " кв.м, " << req.getOffered().getFloor()
            << " этаж, район: " << req.getOffered().getDistrict() << "\n";
    }
}

