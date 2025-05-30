#include "Polygon.h"
#include <iostream>

/**
* @brief Оператор вывода многоугольника в поток
* @param os Выходной поток
* @param p Многоугольник для вывода
* @return Ссылка на выходной поток
*/
std::ostream& operator<<(std::ostream& os, const Polygon& p) {
    os << p.ToString();
    return os;
}

/**
* @brief Оператор ввода многоугольника из потока
* @param is Входной поток
* @param p Многоугольник для ввода
* @return Ссылка на входной поток
*/
std::istream& operator>>(std::istream& is, Polygon& p) {
    p.read(is);
    return is;
}