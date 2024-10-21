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
 * @param x константа из введенного интервала
 * @return значение функции
 */
double y(const double x);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите начало интервала:");
    double start = Input();
    puts("Введите конец интервала:");
    double end = Input();
    puts("Введите шаг:");
    double step = Input();
    printf("x\ty\n");
    for (double x = start; x < (end + step); x += step)
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

double y(const double x)
{
    return 0.29 * pow(x, 3) + x - 1.2502;   
}