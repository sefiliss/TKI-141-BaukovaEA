#pragma once

/**
*@brief класс, представляющий точку в двухмерном пр-ве
*/

class Point
{
private:
	double x;
	double y;
public:
    /**
	*@breif конструктор класса Point
	*@param x координата по оси x
	*@param y координата по оси y
	*/
	Point(const double x = 0.0, const double y = 0.0);
	/**
	*@brief получение координаты x
	*@return координату x
	*/
	double getX() const;
	/**
	*@brief получение координаты y
	*@return координату y
	*/
	double getY() const;
};

/**
* @brief Оператор сравнения точек на равенство
* @param point1 Первая точка для сравнения
* @param point2 Вторая точка для сравнения
* @return true если точки равны с учетом погрешности вычислений, false в противном случае
*/
bool operator==(const Point& point1, const Point& point2);
/**
* @brief Оператор сравнения точек на неравенство
* @param point1 Первая точка для сравнения
* @param point2 Вторая точка для сравнения
* @return true если точки не равны с учетом погрешности вычислений, false в противном случае
*/
bool operator!=(const Point& point1, const Point& point2);