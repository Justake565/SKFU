#pragma once
#ifndef APARTMENT_EXCHANGE_H //Эти директивы предназначены для защиты от многократного включения 
#define APARTMENT_EXCHANGE_H

#include <iostream>
#include <list> //для использования двусвязного списка.
#include <fstream> //для работы с файлами.
#include <string>
using namespace std;
class Apartment { //для описания квартир
public:
    int rooms;           // Количество комнат
    double area;        // Площадь
    int floor;          // Этаж
    string district; // Район

    Apartment(int r, double a, int f, const string& d)
        : rooms(r), area(a), floor(f), district(d) {
    }
};

class ExchangeRequest { //для заявки на обмен
public:
    Apartment desired;  // Искомая квартира
    Apartment offered;  // Имеющаяся квартира

    ExchangeRequest(const Apartment& d, const Apartment& o)
        : desired(d), offered(o) {
    }
};

class ApartmentExchange { //для управления списком заявок
private:
    list<ExchangeRequest> requests; // Список заявок

public:
    void addRequest(const ExchangeRequest& request);
    void findMatch(const ExchangeRequest& request);
    void displayRequests() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif 
