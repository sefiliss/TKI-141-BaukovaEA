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
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
    auto x = getCoordinate("Введите координату x: ");
    auto y = getCoordinate("Введите координату y: ");
    Point point1(x, y);

    x = getCoordinate("Введите координату x: ");
    y = getCoordinate("Введите координату y: ");
    Point point2(x, y);

    x = getCoordinate("Введите координату x: ");
    y = getCoordinate("Введите координату y: ");
    Point point3(x, y);

    x = getCoordinate("Введите координату x: ");
    y = getCoordinate("Введите координату y: ");
    Point point4(x, y);

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