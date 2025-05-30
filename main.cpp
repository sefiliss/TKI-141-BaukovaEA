#include <iostream>
#include "Square.h"

using namespace std;
/**
*@brief Точка входа в программу
*@return Код завершения программы (0 - успех, 1 - ошибка)
*/
int main(){
    try {
        // Создание квадрата по умолчанию
        Square sq1;
        cout << "Квадрат по умолчанию: " << sq1 << endl;
        cout << "Площадь: " << sq1.area() << ", Периметр: " << sq1.perimeter() << ", Радиус описанной окружности: " << sq1.circumradius() << endl << endl;
        // Создание квадрата через ввод 4 точек с клавиатуры
        cout << "Введите 4 точки для квадрата (x y для каждой точки):" << endl;
        Square sq2 = Square::readFromStream(cin);
        cout << "Ваш квадрат: " << sq2 << endl;
        cout << "Площадь: " << sq2.area() << ", Периметр: " << sq2.perimeter() << ", Радиус описанной окружности: " << sq2.circumradius() << endl << endl;
        // Создание квадрата через ввод координат вершин
        cout << "Введите координаты 4 вершин квадрата (x1 y1 x2 y2 x3 y3 x4 y4):" << endl;
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Square sq3(x1, y1, x2, y2, x3, y3, x4, y4);
        cout << "Ваш квадрат: " << sq3 << endl;
        cout << "Площадь: " << sq3.area() << ", Периметр: " << sq3.perimeter() << ", Радиус описанной окружности: " << sq3.circumradius() << endl << endl;

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}

    