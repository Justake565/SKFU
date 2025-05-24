#include "MyStrings.h"
using namespace std;
// Реализация методов класса SymbString
SymbString::SymbString(const string& identifier, const string& val)
    : BaseString(identifier), value(val) {
}

void SymbString::show() const { //Выводит идентификатор и значение символической строки на экран.
    cout << "SymbString [" << id << "]: " << value << endl;
}

SymbString SymbString::operator+(const SymbString& other) const {
    return SymbString(id, value + other.value);
}

SymbString SymbString::operator-(const SymbString& other) const {
    string::size_type pos = value.find(other.value);
    if (pos != string::npos) {
        string newValue = value; // Создаем копию текущего значения
        newValue.erase(pos, other.value.length()); // Удаляем подстроку
        return SymbString(id, newValue); // Возвращаем новый объект
    }
    return *this; // Если подстрока не найдена, возвращаем текущий объект
}

// Реализация методов класса BinString
BinString::BinString(const string& identifier, int val)
    : BaseString(identifier), value(val) {
}

void BinString::show() const {
    cout << "BinString [" << id << "]: " << bitset<8>(value) << endl; // Для простоты, 8 бит
}

BinString BinString::operator+(const BinString& other) const {
    return BinString(id, value + other.value);
}

BinString BinString::operator-(const BinString& other) const {
    return BinString(id, value - other.value);
}

// Фабрика для создания и удаления объектов
BaseString* Factory::createSymbString(const string& id, const string& value) {
    return new SymbString(id, value);
}

BaseString* Factory::createBinString(const string& id, int value) {
    return new BinString(id, value);
}

void Factory::deleteObject(BaseString* obj) {
    delete obj;
}
