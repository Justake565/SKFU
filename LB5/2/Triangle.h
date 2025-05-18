#pragma once

#ifndef TRIANGLEJ
#define TRIANGLEJ

#include "Point.h"

class Triangle {
public:
	Triangle(Point, Point, Point, const char*); // конструктор
	Triangle(const char*); //конструктор пустого (нулевого) объекта 
	~Triangle(); //деструктор

	Point Get_v1() const { return v1; } // Получить значение v1
	Point Get_v2() const { return v2; } // Получить значение v2
	Point Get_v3() const { return v3; } // Получить значение v3
	char* GetName() const { return name; } // Получить имя объекта
	void Show() const; // Показать объект
	void ShowSideAndArea() const; // Показать стороны и площадь объекта

public:
	static int count; //кол-во созданных объектов

private:
	char* objID; // идентификатор объекта
	char* name; // наименование треугольника
	Point v1, v2, v3; //вершины
	double a; // сторона, соединяющая v1 и v2
	double b; // сторона, соединяющая v2 и v3
	double c; // сторона, соединяющая v1 и v3
};

#endif
