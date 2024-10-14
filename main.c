#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает вещественное число
 * @return вещественное число
 */
double Input(void);

/**
 * @brief считывает вещественное число с проверкой знака
 * @return положительное число в случае успеха
 */
double PositiveInput(void);

/**
 * @brief вычисляет гипотенузу треугольника
 * @param cat1 первый катет треугольника
 * @param cat2 второй кавтет треугольника
 * @return гипотенузу треугольника
 */
double GetH(const double cat1, const double cat2);

/**
 * @brief вычисляет периметр треугольника по двум катетам
 * @param cat1 первый катет треугольника
 * @param cat2 второй катет треугольника
 * @return периметр треугольника
 */
double GetP(const double cat1, const double cat2);

/**
 * @brief вычисляет площадь треугольника по двум катетам
 * @param cat1 первый катет треугольника
 * @param cat2 второй кавтет треугольника
 * @return площадь треугольника
 */
double GetArea(const double cat1, const double cat2);

/**
 * @brief считывает целое число
 * @return целое число 
 */
int ChoiceInput(void);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите первый катет");
    const double cat1 = PositiveInput();
    puts("Введите второй катет");
    const double cat2 = PositiveInput();
    puts("Введите 0 для вычисления периметра или 1 для вычисления площади");
    const int choice = ChoiceInput();
    

    switch (choice)
    {
    case 0:
        printf("Периметр треугольника равен %lf", GetP(cat1, cat2));
        break;
    
    case 1:
        printf("Площадь треугольника равна %lf", GetArea(cat1, cat2));
        break;
    default:
        printf("Такой операции не существует");
        break;
    }
    return 0;
}

double Input(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Введено не число");
        exit(EXIT_FAILURE);
    }
    return value;
}

double PositiveInput(void)
{
    double value = Input();
    if (value <= 0)
    {
        printf("Неккоректное значение катета");
        exit(EXIT_FAILURE);
    }
    return value;
}


double GetH(const double cat1, const double cat2)
{
    return sqrt(pow(cat1, 2) + pow(cat2, 2));
}

double GetP(const double cat1, const double cat2)
{
    return GetH(cat1, cat2) + cat1 + cat2;
}

double GetArea(const double cat1, const double cat2)
{
    return cat1 * cat2 * 0.5;
}

int ChoiceInput(void)
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Неккоректный выбор");
        exit(EXIT_FAILURE);
    }
    return value;
}
