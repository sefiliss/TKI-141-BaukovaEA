#pragma once
#include "Polygon.h"
#include <vector>

/**
* @brief Класс, представляющий квадрат (правильный четырехугольник)
*/
class Square : public Polygon
{
private:
    std::vector<Point> vertices; ///< Вектор вершин квадрата
    
    /**
    * @brief Проверка валидности квадрата
    * @return true если точки образуют квадрат, false в противном случае
    */
    bool isValid() const;
    
    /**
    * @brief Вычисление длины стороны квадрата
    * @return Длина стороны квадрата
    */
    double sideLength() const;
    
public:
    /**
    * @brief Конструктор по умолчанию (создает единичный квадрат)
    */
    Square();
    
    /**
    * @brief Конструктор по точкам вершин
    * @param points Вектор точек вершин
    * @throw std::invalid_argument если точки не образуют квадрат
    */
    Square(const std::vector<Point>& points);
    
    /**
    * @brief Конструктор по координатам вершин
    * @param x1,y1 Координаты первой вершины
    * @param x2,y2 Координаты второй вершины
    * @param x3,y3 Координаты третьей вершины
    * @param x4,y4 Координаты четвертой вершины
    * @throw std::invalid_argument если точки не образуют квадрат
    */
    Square(double x1, double y1, double x2, double y2, 
           double x3, double y3, double x4, double y4);
    
    // Реализация виртуальных методов Polygon
    std::string ToString() const override;
    double area() const override;
    double perimeter() const override;
    double circumradius() const override;
    void read(std::istream& is) override;
    
    /**
    * @brief Статический метод сериализации в строку
    * @param square Квадрат для сериализации
    * @return Строковое представление квадрата
    */
    static std::string ToString(const Square& square);
    
    /**
    * @brief Статический метод чтения из потока ввода
    * @param is Входной поток
    * @return Объект Square, прочитанный из потока
    */
    static Square readFromStream(std::istream& is);
    
    /**
    * @brief Оператор сравнения квадратов на равенство
    * @param other Квадрат для сравнения
    * @return true если квадраты равны, false в противном случае
    */
    bool operator==(const Square& other) const;
    
    /**
    * @brief Оператор сравнения квадратов на неравенство
    * @param other Квадрат для сравнения
    * @return true если квадраты не равны, false в противном случае
    */
    bool operator!=(const Square& other) const;
};