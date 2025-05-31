#include "Point.h"
#include <iostream>

/**
* @brief Конструктор класса Point
* @param x Координата по оси X (по умолчанию 0.0)
* @param y Координата по оси Y (по умолчанию 0.0)
*/
Point::Point(const double x, const double y) : x(x), y(y) {}

/**
* @brief Получение координаты X
* @return Значение координаты X
*/
double Point::getX() const {
    return x;
}

/**
* @brief Получение координаты Y
* @return Значение координаты Y
*/
double Point::getY() const {
    return y;
}

/**
* @brief Оператор ввода точки из потока
* @param is Входной поток
* @param p Точка для ввода
* @return Ссылка на входной поток
*/
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

/**
* @brief Оператор вывода точки в поток
* @param os Выходной поток
* @param p Точка для вывода
* @return Ссылка на выходной поток
*/
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

/**
* @brief Оператор сравнения точек на равенство
* @param other Точка для сравнения
* @return true если точки равны, false в противном случае
*/
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

/**
* @brief Оператор сравнения точек на неравенство
* @param other Точка для сравнения
* @return true если точки не равны, false в противном случае
*/
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}