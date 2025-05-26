#include <stdexcept>
#include <cmath>
#include <limits>
#include "Rectangle.h"

Rectangle::Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4):
	point1{ point1 }, point2{ point2 }, point3{ point3 }, point4{ point4 }
{
	if (!isRectangle())
	{
		throw std::logic_error("Точки не образуют прямоугольник");
	}
	side1 = distance(point1, point2);
	side2 = distance(point2, point3);
	side3 = distance(point3, point4);
	side4 = distance(point4, point1);
}


double Rectangle::getSide1() const
{
	return side1;
}

double Rectangle::getSide2() const
{
	return side2;
}

double Rectangle::getSide3() const
{
	return side3;
}

double Rectangle::getSide4() const
{
	return side4;
}

double Rectangle::perimetr() const
{
    return 2 * (side1 + side2); 
}

double Rectangle::area() const
{
    return side1 * side2;
}

double Rectangle::distance(const Point& p1, const Point& p2) const
{
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return std::sqrt(dx*dx + dy*dy);
}

bool Rectangle::isRectangle() const
{
    bool sidesEqual = (std::abs(distance(point1, point2) - distance(point3, point4)) <= std::numeric_limits<double>::epsilon()) &&
                     (std::abs(distance(point2, point3) - distance(point1, point4)) <= std::numeric_limits<double>::epsilon());

    bool rightAngles = isRightAngle(point1, point2, point3) &&
                       isRightAngle(point2, point3, point4) &&
                       isRightAngle(point3, point4, point1) &&
                       isRightAngle(point4, point1, point2);
    
    return sidesEqual && rightAngles;
}

bool Rectangle::isRightAngle(const Point& a, const Point& b, const Point& c) const
{
    double abx = b.getX() - a.getX();
    double aby = b.getY() - a.getY();
    double bcx = c.getX() - b.getX();
    double bcy = c.getY() - b.getY();
    
    double dotProduct = abx * bcx + aby * bcy;
    return std::abs(dotProduct) <= std::numeric_limits<double>::epsilon();
}