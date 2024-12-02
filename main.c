#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief считывает целое число
 * @return целое число
 */
int DInput(void);

/**
 * @brief считывает целое число и проверяет знак
 * @return целое число, если оно положительное
 */
int DPositiveInput(void);

/**
 * @brief считывает вещественное число
 * @return вещественное число
 */
double FInput(void);

/**
 * @brief считывает вещественное число и проверяет знак
 * @return вещественное число, если оно положительное
 */
double FPositiveInput(void);

/**
 * @brief вычисление k-того элемента с помощью k-1 элемета
 * @param current k-1 элемент
 * @param k номер вычисляемого элемента
 * @return k-тый элемент
 */
double GetElement(int k);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите n");
    const int end = DPositiveInput();
    const double zeroelement = 1.0;
    double current = zeroelement;
    double sumA = 0.0;
    for (int i = 1; i <= end; i++)
    {
        sumA += current;
        current *= GetElement(i);
    }
    puts("Введите значение числа e");
    const double eps = FPositiveInput();
    double sumB = 0.0;
    current = zeroelement;
    for (int i = 1; fabs(current) >= eps; i++)
    {
        sumB += current;
        current *= GetElement(i);
    }
    printf("%lf\n%lf\n", sumA, sumB);
    
    return 0;
}

int DInput(void)
{
    int value = 0;
    if(scanf("%d", &value) != 1)
    {
        puts("Не является целым числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

int DPositiveInput(void)
{
    int value =  DInput();
    if (value <= 0)
    {
        puts("Не является целым положительным числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double FInput(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double FPositiveInput(void)
{
    double value = FInput();
    if (value <= DBL_EPSILON)
    {
        puts("Не является положительным числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double GetElement(int k)
{
    return (-1)/(pow(k, 2)+k);
}
