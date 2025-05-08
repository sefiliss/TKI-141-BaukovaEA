#pragma once
#include "Point.h"
/**
 * @brief Класс, представляющий прямоугольник в двумерном пространстве
 */
class Rectangle
{
private:
	Point point1;//левая нижняя вершина
	Point point2;//левая верхняя вершина
	Point point3;//правая верхняя вершина
	Point point4;//правая нижняя вершина
	double side1;//длина м-ду p1 и p2
	double side2;//длина м-ду p2 и p3
	double side3;////длина м-ду p3 и p4
	double side4;//длина м-ду p4 и p1
	/**
     * @brief Вычисляет расстояние между двумя точками
     * @param p1 Первая точка
     * @param p2 Вторая точка
     * @return Расстояние между точками
     */
	double distance(const Point& p1, const Point& p2) const;
	 /**
     * @brief Проверяет, является ли угол прямым
     * @param a Первая точка угла
     * @param b Вершина угла
     * @param c Третья точка угла
     * @return true если угол прямой, false в противном случае
     */
	bool isRightAngle(const Point& a, const Point& b, const Point& c) const;
	 /**
     * @brief Проверяет, образуют ли точки прямоугольник
     * @return true если все условия прямоугольника выполнены, false в противном случае
     */
	bool isRectangle() const;
public:
	 /**
     * @brief Конструктор прямоугольника по четырем точкам
     * @param point1 Первая вершина
     * @param point2 Вторая вершина
     * @param point3 Третья вершина
     * @param point4 Четвертая вершина
     */
	Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4);
	 /**
     * @brief Получает длину первой стороны (между point1 и point2)
     * @return Длину стороны типа double
     */
	double getSide1() const;
	 /**
     * @brief Получает длину первой стороны (между point2 и point3)
     * @return Длину стороны типа double
     */
	double getSide2() const;
	 /**
     * @brief Получает длину первой стороны (между point3 и point4)
     * @return Длину стороны типа double
     */
	double getSide3() const;
	 /**
     * @brief Получает длину первой стороны (между point4 и point1)
     * @return Длину стороны типа double
     */
	double getSide4() const;
	 /**
     * @brief Вычисляет периметр прямоугольника
     * @return Значение периметра типа double
     */
	double perimetr() const;
	 /**
     * @brief Вычисляет площадь прямоугольника
     * @return Значение площади типа double
     */
	double area() const;
};