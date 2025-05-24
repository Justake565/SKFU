#ifndef MYSTRINGS_H
#define MYSTRINGS_H

#include <iostream>
#include <string>
#include <bitset> //для представления данных в двоичном формате.
#include <sstream>
#include <stdexcept>
//для работы со строками и обработки исключений соответственно.
class BaseString {
protected:
    string id;

public:
    BaseString(const string& identifier) : id(identifier) {}
    virtual ~BaseString() {}

    string getId() const { return id; }
    virtual void show() const = 0; // Чисто виртуальная функция
};

class SymbString : public BaseString { //для работы с символическими строками
private:
    string value;

public:
    SymbString(const string& identifier, const string& val);
    void show() const override;
    SymbString operator+(const SymbString& other) const;
    SymbString operator-(const SymbString& other) const;
};

class BinString : public BaseString {
private:
    int value;

public:
    BinString(const string& identifier, int val);
    void show() const override;
    BinString operator+(const BinString& other) const;
    BinString operator-(const BinString& other) const;
};

// Фабрика для создания и удаления объектов
class Factory {
public:
    static BaseString* createSymbString(const string& id, const string& value);
    static BaseString* createBinString(const string& id, int value);
    static void deleteObject(BaseString* obj);
};

#endif // MYSTRINGS_H
