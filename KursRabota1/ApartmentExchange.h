#pragma once
#ifndef APARTMENT_EXCHANGE_H
#define APARTMENT_EXCHANGE_H

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

// Класс, описывающий квартиру с основными характеристиками
class Apartment {
private:
    int rooms;       // Количество комнат в квартире
    double area;     // Площадь квартиры в кв.м
    int floor;       // Этаж расположения квартиры
    string district; // Район города, где находится квартира

public:
    // Конструктор с параметрами по умолчанию
    Apartment(int r = 0, double a = 0.0, int f = 0, const string& d = "")
        : rooms(r), area(a), floor(f), district(d) {
    }

    // Методы доступа (геттеры) для получения значений полей
    int getRooms() const { return rooms; }
    double getArea() const { return area; }
    int getFloor() const { return floor; }
    string getDistrict() const { return district; }

    // Методы изменения (сеттеры) для установки значений полей
    void setRooms(int r) { rooms = r; }
    void setArea(double a) { area = a; }
    void setFloor(int f) { floor = f; }
    void setDistrict(const string& d) { district = d; }
};

// Класс, представляющий заявку на обмен квартирами
class ExchangeRequest {
private:
    Apartment desired;  
    Apartment offered;  

public:
    // Конструктор с параметрами по умолчанию
    ExchangeRequest(const Apartment& d = Apartment(), const Apartment& o = Apartment())
        : desired(d), offered(o) {
    }

    // Методы доступа к полям класса
    Apartment getDesired() const { return desired; }
    Apartment getOffered() const { return offered; }

    // Методы изменения полей класса
    void setDesired(const Apartment& d) { desired = d; }
    void setOffered(const Apartment& o) { offered = o; }
};

// Абстрактный базовый класс для системы обмена квартирами
class BaseExchange {
protected:
    list<ExchangeRequest> requests;  // Список всех заявок на обмен
    string currentFilename = "requests.txt";  

public:
    // Чисто виртуальные методы, которые должны быть реализованы в производных классах
    virtual void addRequest(const ExchangeRequest& request) = 0;  // Добавление новой заявки
    virtual bool findMatch(const ExchangeRequest& request) = 0;   // Поиск совпадений
    virtual void displayRequests() const = 0;  // Отображение всех заявок
    virtual bool removeRequest(const ExchangeRequest& request) = 0;  // Удаление заявки
    virtual void saveToFile(const string& filename) const = 0;  // Сохранение в файл
    virtual void loadFromFile(const string& filename) = 0;  // Загрузка из файла
    virtual ~BaseExchange() {}  // Виртуальный деструктор
};

// Конкретный класс реализации системы обмена квартирами
class ApartmentExchange : public BaseExchange {
public:
    // Реализации виртуальных методов
    void addRequest(const ExchangeRequest& request) override;
    bool findMatch(const ExchangeRequest& request) override;
    void displayRequests() const override;
    bool removeRequest(const ExchangeRequest& request) override;
    void saveToFile(const string& filename) const override;
    void loadFromFile(const string& filename) override;
};

#endif
