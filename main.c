﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief считывает вещественное число
 * @return вещественное число
 */
double Input(void);

/**
 * @brief вычисляет функцию
 * @param a параметр, данный в таблице
 * @param x значение, введенное пользователем
 * @return значение функции
 */
double y(const double a, const double x);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    const double a = 2.0;
    puts("Введите значение x");
    const double x = Input();
    printf("Значение функции:%lf при x равном %lf", y(a, x), x);
    return 0;
}

double Input(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double y(const double a, const double x)
{
    if(x < 1)
    {
        return 1;
    }
    if(x > 2)
    {
        return exp(a * x) * cos(x);
    }
    return a * pow(x, 2*log(x));
}
