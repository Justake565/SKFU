#include "ApartmentExchange.h"
void ApartmentExchange::addRequest(const ExchangeRequest& request) { //Добавляет новую заявку в список requests.
    requests.push_back(request);
}

void ApartmentExchange::findMatch(const ExchangeRequest& request) { //Этот метод ищет совпадения для переданной заявки.
    auto it = requests.begin();
    while (it != requests.end()) {
        if (it->desired.rooms == request.offered.rooms &&
            it->desired.floor == request.offered.floor &&
            abs(it->desired.area - request.offered.area) <= 0.1 * it->desired.area) {

            cout << "Найдено совпадение:\n";
            cout << "Искомая квартира: " << it->desired.rooms << " комнат, "
                << it->desired.area << " кв.м, Этаж: " << it->desired.floor
                << ", Район: " << it->desired.district << "\n";
            cout << "Имеющаяся квартира: " << it->offered.rooms << " комнат, "
                << it->offered.area << " кв.м, Этаж: " << it->offered.floor
                << ", Район: " << it->offered.district << "\n";
            it = requests.erase(it); // Удаляем найденную заявку
            return;
        }
        else {
            ++it;
        }
    }
    addRequest(request); // Если совпадений нет, добавляем заявку в список
}

void ApartmentExchange::displayRequests() const { //Этот метод отображает все заявки в списке. 
    if (requests.empty()) {
        cout << "Картотека пуста.\n";
        return;
    }

    for (const auto& req : requests) {
        cout << "Искомая квартира: " << req.desired.rooms << " комнат, "
            << req.desired.area << " кв.м, Этаж: " << req.desired.floor
            << ", Район: " << req.desired.district << "\n";
        cout << "Имеющаяся квартира: " << req.offered.rooms << " комнат, "
            << req.offered.area << " кв.м, Этаж: " << req.offered.floor
            << ", Район: " << req.offered.district << "\n";
    }
}

void ApartmentExchange::saveToFile(const string& filename) const { //Сохраняет все заявки в указанный файл.
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& req : requests) {
            file << req.desired.rooms << ","
                << req.desired.area << ","
                << req.desired.floor << ","
                << req.desired.district << "\n"
                << req.offered.rooms << ","
                << req.offered.area << ","
                << req.offered.floor << ","
                << req.offered.district << "\n";
        }
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл для записи.\n";
    }
}

void ApartmentExchange::loadFromFile(const string& filename) { //Загружает заявки из указанного файла.
    ifstream file(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            int rooms, floor;
            double area;
            string district;

            if (file >> rooms) {
                file.ignore(); // Игнорируем запятую
                file >> area;
                file.ignore();
                file >> floor;
                file.ignore();
                getline(file, district);

                Apartment desired(rooms, area, floor, district);

                file >> rooms;
                file.ignore(); // Игнорируем запятую
                file >> area;
                file.ignore();
                file >> floor;
                file.ignore();
                getline(file, district);

                Apartment offered(rooms, area, floor, district);

                ExchangeRequest request(desired, offered);
                addRequest(request);
            }
        }
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл для чтения.\n";
    }
}
