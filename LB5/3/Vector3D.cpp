#include "Vector3D.h"
using namespace std;
// Конструктор
Vector3D::Vector3D(double x1, double y1, double z1, double x2, double y2, double z2)
    : x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2) {
}

// Метод для получения координат вектора
void Vector3D::getCoordinates(double& x, double& y, double& z) const {
    x = x2 - x1;
    y = y2 - y1;
    z = z2 - z1;
}

// Операция сложения
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x1, y1, z1, x2 + (other.x2 - other.x1), y2 + (other.y2 - other.y1), z2 + (other.z2 - other.z1));
}

// Операция вычитания
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x1, y1, z1, x2 - (other.x2 - other.x1), y2 - (other.y2 - other.y1), z2 - (other.z2 - other.z1));
}

// Метод для вычисления скалярного произведения
double Vector3D::dotProduct(const Vector3D& other) const {
    double xA, yA, zA;
    double xB, yB, zB;
    this->getCoordinates(xA, yA, zA);
    other.getCoordinates(xB, yB, zB);
    return (xA * xB + yA * yB + zA * zB);
}

// Метод для вычисления длины вектора
double Vector3D::length() const {
    double xA, yA, zA;
    getCoordinates(xA, yA, zA);
    return sqrt(xA * xA + yA * yA + zA * zA);
}

// Метод для вычисления косинуса угла между векторами
double Vector3D::cosineAngle(const Vector3D& other) const {
    double dotProd = this->dotProduct(other);
    return dotProd / (this->length() * other.length());
}

// Метод для вывода вектора
void Vector3D::print() const {
    cout << "Vector from (" << x1 << ", " << y1 << ", " << z1 << ") to (" << x2 << ", " << y2 << ", " << z2 << ")" << std::endl;
}
