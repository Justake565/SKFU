#pragma once
#ifndef POINT_H
#define POINT_H

class Point {
public:
	
	Point(double _õ = 0, double _ó = 0) : x(_õ), y(_ó) {}

	
	void Show() const;

public:
	double x, y;
};

#endif
