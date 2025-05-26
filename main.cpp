#include <iostream>
#include <string>
#include<limits>
#include "Point.h"
#include "Rectangle.h"
/**
 * @brief Функция для безопасного ввода координат с клавиатуры
 * @param message Сообщение для вывода
 * @return Введенное значение координаты
 */
double getCoordinate(std::string message);

/**
 * @brief Функция получения точки
 * @param point_name Сообщение для вывода с названием вводимой точки
 * @return Объект точки Point с введенными координатами
 */
Point getPoint(std::string point_name);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
    Point point1 = getPoint("1(левый нижняя вершина)");
    Point point2 = getPoint("2(левый верхняя вершина)");
    Point point3 = getPoint("3(правая верхняя вершина)");
    Point point4 = getPoint("4(правая нижняя вершина)");

    Rectangle rectangle(point1, point2, point3, point4);
    std::cout << "Периметр равен " << rectangle.perimetr() << std::endl;
    std::cout << "Площадь равна " << rectangle.area() << std::endl;
    } catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

double getCoordinate(std::string message)
{
    std::cout << message << std::endl;
    double coordinate = 0.0;
    std::cin >> coordinate;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Введено некорректное значение");
    }
    return coordinate;
}

Point getPoint(std::string point_name)
{
    std::cout << "\n Ввод точки " << point_name << std::endl;
    double x = getCoordinate("Введите координату x: ");
    double y = getCoordinate("Введите координату y: ");
    return Point(x, y);
}
