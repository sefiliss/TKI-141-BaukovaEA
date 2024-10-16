#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>
/**
 * @brief считывает вещественное число
 * @return вещественное число
 */
double Input(void);

/**
 * @brief считывает вещественное число с проверкой знака
 * @return вещественное число в случае, если оно больше нуля
 */
double PositiveInput(void);

/**
 * @brief определяет, пройдет ли кирпич в отверстие
 * @param x длина стороны x кирпича
 * @param y длина стороны y кирпича
 * @param z длина стороны z кирпича
 * @param r длина стороны r отверстия
 * @param s длина стороны s отверстия
 * @return true, если кирпич проходит и false, если не проходит
 */
bool ifKirpichEnter(const double x, const double y, const double z, const double r, const double s);

/**
 * @brief точка входа в пронрамму
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите длину стороны x кирпича ");
    const double x = PositiveInput();
    puts("Введите длину стороны y кирпича ");
    const double y = PositiveInput();
    puts("Введите длину стороны z кирпича ");
    const double z = PositiveInput();
    puts("Введите длину стороны r отверстия ");
    const double r = PositiveInput();
    puts("Введите длину стороны s отверстия ");
    const double s = PositiveInput();
    if (ifKirpichEnter(x, y, z, r, s) == true)
    {
        puts("Кирпич проходит в отверстие");
        return 0;
    };
    puts("Кирпич не проходит в отверстие");
    return 0;
}

double Input(void)
{
    double value = 0.0;
    if(scanf("%lf", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double PositiveInput(void)
{
    double value = Input();
    if (value <= 0)
    {
        puts("Некорректное значение длины");
        exit(EXIT_FAILURE);
    }
    return value;
}

bool ifKirpichEnter(const double x, const double y, const double z, const double r, const double s)
{
    if (x<=r && y<=s || x<=r && z<=s || y<=r && x<=s || y<=r && z<=s || z<=r && x<=s || z<=r && y<=s)
    {
        return true ;
    }
    return false;
}
