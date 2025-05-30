#include "Square.h"
#include "Polygon.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <limits>
#include <iostream>

using namespace std;
/**
*@brief Проверяет, образуют ли вершины квадрат
*@return true если вершины образуют квадрат, false в противном случае
*/
bool Square::isValid() const {
    if (vertices.size() != 4) return false;
    
    // Проверяем длины всех сторон
    auto dist = [](const Point& a, const Point& b) {
        double dx = b.getX() - a.getX();
        double dy = b.getY() - a.getY();
        return sqrt(dx*dx + dy*dy);
    };
    
    double side = dist(vertices[0], vertices[1]);
    if (abs(dist(vertices[1], vertices[2]) - side) > numeric_limits<double>::epsilon()) return false;
    if (abs(dist(vertices[2], vertices[3]) - side) > numeric_limits<double>::epsilon()) return false;
    if (abs(dist(vertices[3], vertices[0]) - side) > numeric_limits<double>::epsilon()) return false;
    
    // Проверяем диагонали
    double diag = dist(vertices[0], vertices[2]);
    if (abs(dist(vertices[1], vertices[3]) - diag) > numeric_limits<double>::epsilon()) return false;
    if (abs(diag - side*sqrt(2)) > numeric_limits<double>::epsilon()) return false;
    
    return true;
}
/**
*@brief Вычисляет длину стороны квадрата
*@return Длину стороны квадрата
*/
double Square::sideLength() const {
    if (vertices.empty()) return 0.0;
    double dx = vertices[1].getX() - vertices[0].getX();
    double dy = vertices[1].getY() - vertices[0].getY();
    return sqrt(dx*dx + dy*dy);
}

/**
*@brief Конструктор по умолчанию,создает единичный квадрат с вершинами (0,0), (1,0), (1,1), (0,1)
*/
Square::Square() {
    vertices = {Point(0,0), Point(1,0), Point(1,1), Point(0,1)};
}

/**
*@brief Конструктор по вектору точек
*@param points Вектор из 4 точек - вершин квадрата
*@throw std::invalid_argument если точки не образуют квадрат
*/
Square::Square(const vector<Point>& points) : vertices(points) {
    if (!isValid()) {
        throw invalid_argument("Неверные точки");
    }
}
/**
*@brief Конструктор по координатам вершин
*@param x1,y1 Координаты первой вершины
*@param x2,y2 Координаты второй вершины
*@param x3,y3 Координаты третьей вершины
*@param x4,y4 Координаты четвертой вершины
*@throw std::invalid_argument если координаты не образуют квадрат
*/
Square::Square(double x1, double y1, double x2, double y2, 
               double x3, double y3, double x4, double y4) {
    vertices = {Point(x1,y1), Point(x2,y2), Point(x3,y3), Point(x4,y4)};
    if (!isValid()) {
        throw invalid_argument("Неверные координаты");
    }
}

/**
*@brief Преобразует квадрат в строковое представление
*@return Строку с информацией о квадрате
*/
string Square::ToString() const {
    ostringstream oss;
    oss << "Квадрат с вершинами: ";
    for (const auto& p : vertices) {
        oss << p << " ";
    }
    oss << "(длина стороны: " << sideLength() << ")";
    return oss.str();
}

/**
*@brief Вычисляет площадь квадрата
*@return Площадь квадрата
*/
double Square::area() const {
    double side = sideLength();
    return side * side;
}

/**
* @brief Вычисляет периметр квадрата
* @return Периметр квадрата
*/
double Square::perimeter() const {
    return 4 * sideLength();
}

/**
*@brief Вычисляет радиус описанной окружности
*@return Радиус описанной окружности
*/
double Square::circumradius() const {
    return sideLength() * sqrt(2) / 2;
}

/**
*@brief Читает квадрат из потока ввода
*@param is Входной поток
*@throw std::invalid_argument если введенные точки не образуют квадрат
*/
void Square::read(istream& is) {
    vector<Point> points;
    cout << "Введите 4 точки (x y для каждой):" << endl;
    for (int i = 0; i < 4; ++i) {
        Point p;
        is >> p;
        points.push_back(p);
    }
    
    Square temp(points);
    if (!temp.isValid()) {
        throw invalid_argument("Неверный ввод квадрата");
    }
    vertices = points;
}

/**
*@brief Статический метод для преобразования квадрата в строку
*@param square Квадрат для преобразования
*@return Строковое представление квадрата
*/
string Square::ToString(const Square& square) {
    return square.ToString();
}

/**
*@brief Статический метод для чтения квадрата из потока
*@param is Входной поток
*@return Объект Square, прочитанный из потока
*@details Использует метод read() для чтения данных
*/
Square Square::readFromStream(istream& is) {
    Square sq;
    sq.read(is);
    return sq;
}

/**
*@brief Оператор сравнения квадратов на равенство
*@param other Квадрат для сравнения
*@return true если квадраты равны, false в противном случае
*@details Сравнивает вершины квадратов
*/
bool Square::operator==(const Square& other) const {
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i] != other.vertices[i]) {
            return false;
        }
    }
    return true;
}

/**
*@brief Оператор сравнения квадратов на неравенство
*@param other Квадрат для сравнения
*@return true если квадраты не равны, false в противном случае
*/
bool Square::operator!=(const Square& other) const {
    return !(*this == other);
}