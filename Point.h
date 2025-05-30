#pragma once
#include <iostream>

/**
* @brief Класс, представляющий точку в двухмерном пространстве
*/
class Point
{
private:
    double x;
    double y;
public:
    /**
    * @brief Конструктор класса Point
    * @param x Координата по оси X (по умолчанию 0.0)
    * @param y Координата по оси Y (по умолчанию 0.0)
    */
    Point(const double x = 0.0, const double y = 0.0);
    
    /**
    * @brief Получение координаты X
    * @return Значение координаты X
    */
    double getX() const;
    
    /**
    * @brief Получение координаты Y
    * @return Значение координаты Y
    */
    double getY() const;
    
    /**
    * @brief Оператор ввода точки из потока
    * @param is Входной поток
    * @return Ссылку на входной поток
    */
    friend std::istream& operator>>(std::istream& is, Point& p);
    
    /**
    * @brief Оператор вывода точки в поток
    * @param os Выходной поток
    * @return Ссылку на выходной поток
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    /**
    * @brief Оператор сравнения точек на равенство
    * @param other Точка для сравнения
    * @return true если точки равны, false в противном случае
    */
    bool operator==(const Point& other) const;
    
    /**
    * @brief Оператор сравнения точек на неравенство
    * @param other Точка для сравнения
    * @return true если точки не равны, false в противном случае
    */
    bool operator!=(const Point& other) const;
};