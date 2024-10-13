#include <stdio.h>

/**
 * @brief считывает вещественное число
 * @return возвращает вещественное число
 */
double Input(void);

/**
 * @brief рассчитывает площадь грани
 * @param length длина ребра куба
 * @return площадь грани
 */
double GetAreaG(const double length);

/**
 * @brief рассчитывает площадь полной поверхности куба
 * @param length длина ребра куба
 * @return площадь полной поверхности куба
 */
double GetAreaF(const double length);

/**
 * @brief рассчитывает объем куба
 * @param length длина ребра куба
 * @return объем куба
 */
double GetVolume(const double length);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
*/
int main(void)
{
    puts("Введите длину грани куба");
    double length = Input();
    printf("Площадь грани куба,%lf\nПлощадь полной поверхности куба,%lf\nОбъем куба,%lf",GetAreaG(length),GetAreaF(length),GetVolume(length));
    return 0;
}

double Input(void)
{
    double value = 0.0;
    scanf("%lf", &value);

    return value;
}

double GetAreaG(const double length)
{
    return length * length;
}

double GetAreaF(const double length)
{
    return length * length * 6;
}

double GetVolume(const double length)
{
    return length * length * length;
}
