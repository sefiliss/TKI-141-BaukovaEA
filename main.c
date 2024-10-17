#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * @brief считывает вещественное число
 * @return вещественное число 
 */
double Input(void);

/**
 * @brief вычисляет функцию
 * @param x конствнта из введенного интервала
 * @param start начало интервала
 * @param step шаг в интервале
 * @param end конец интервала
 * @return значение функции
 */
double y(double x);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    double x;
    puts("Введите начало интервала:");
    double start = Input();
    puts("Введите конец интервала:");
    double end = Input();
    puts("Введите шаг:");
    double step = Input();
    printf("x\ty\n");
    for (x = start; x <= end; x += step)
    {
        printf("%lf\t%lf\n", x, y(x));
    }
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

double y(double x)
{
    return 0.29 * pow(x, 3) + x - 1.2502;   
}