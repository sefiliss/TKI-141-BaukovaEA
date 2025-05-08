#pragma once
#include "Point.h"

class Rectangle
{
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;
	double side1;
	double side2;
	double side3;
	double side4;
	double distance(const Point& p1, const Point& p2) const;
	bool isRightAngle(const Point& a, const Point& b, const Point& c) const;
	bool isRectangle() const;
public:
	Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4);
	double getSide1() const;
	double getSide2() const;
	double getSide3() const;
	double getSide4() const;
	double perimetr() const;
	double area() const;
};