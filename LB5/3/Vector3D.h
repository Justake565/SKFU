ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>

class Vector3D {
private:
    double x1, y1, z1; 
    double x2, y2, z2; 

public:
    Vector3D(double x1, double y1, double z1, double x2, double y2, double z2);

    // Метод для получения координат вектора
    void getCoordinates(double& x, double& y, double& z) const;

    // Операция сложения
    Vector3D operator+(const Vector3D& other) const;

    // Операция вычитания
    Vector3D operator-(const Vector3D& other) const;

    // Метод для вычисления скалярного произведения
    double dotProduct(const Vector3D& other) const;

    // Метод для вычисления длины вектора
    double length() const;

    // Метод для вычисления косинуса угла между векторами
    double cosineAngle(const Vector3D& other) const;

    // Метод для вывода вектора
    void print() const;
};

#endif
