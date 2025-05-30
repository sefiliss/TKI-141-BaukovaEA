#pragma once
#include "Point.h"
#include <vector>
#include <iostream>

/**
* @brief Абстрактный класс, представляющий правильный многоугольник
*/
class Polygon
{
public:
    /**
    * @brief Виртуальный деструктор
    */
    virtual ~Polygon() = default;
    
    /**
    * @brief Сериализация многоугольника в строку
    * @return Строковое представление многоугольника
    */
    virtual std::string ToString() const = 0;
    
    /**
    * @brief Вычисление площади многоугольника
    * @return Площадь многоугольника
    */
    virtual double area() const = 0;
    
    /**
    * @brief Вычисление периметра многоугольника
    * @return Периметр многоугольника
    */
    virtual double perimeter() const = 0;
    
    /**
    * @brief Вычисление радиуса описанной окружности
    * @return Радиус описанной окружности
    */
    virtual double circumradius() const = 0;
    
    /**
    * @brief Чтение многоугольника из потока ввода
    * @param is Входной поток
    */
    virtual void read(std::istream& is) = 0;
    
    /**
    * @brief Оператор вывода многоугольника в поток
    * @param os Выходной поток
    * @param p Многоугольник для вывода
    * @return Ссылку на выходной поток
    */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& p);
    
    /**
    * @brief Оператор ввода многоугольника из потока
    * @param is Входной поток
    * @param p Многоугольник для ввода
    * @return Ссылку на входной поток
    */
    friend std::istream& operator>>(std::istream& is, Polygon& p);
};