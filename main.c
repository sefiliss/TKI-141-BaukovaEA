#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief считывает целое число
 * @return целое число
 */
int dinput(void);

/**
 * @brief считывает целое число и проверяет знак
 * @return целое число, если оно положительное
 */
int dpositiveinput(void);

/**
 * @brief считывает вещественное число
 * @return вещественное число
 */
double finput(void);

/**
 * @brief считывает вещественное число и проверяет знак
 * @return вещественное число, если оно положительное
 */
double fpositiveinput(void);

/**
 * @brief вычисление k-того элемента с помощью k-1 элемета
 * @param current k-1 элемент
 * @param k номер вычисляемого элемента
 * @return k-тый элемент
 */
double GetElement(const double current, int k);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите n");
    const int end = dpositiveinput();
    const double zeroelement = 1.0;
    double current = zeroelement;
    double sumA = zeroelement;
    for (int i = 1; i <= end; i++)
    {
        current = GetElement(current, i);
        sumA += current;
    }
    puts("Введите значение числа e");
    const double eps = fpositiveinput();
    double sumB = zeroelement;
    for (int i = 1; current > eps; i++)
    {
        current = GetElement(current, i);
        sumB += current;
    }
    printf("%lf/n", sumA);
    printf("%lf/n", sumB);
    
    return 0;
}

int dinput(void)
{
    int value = 0;
    if(scanf("%d", &value) != 1)
    {
        puts("Не является целым числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

int dpositiveinput(void)
{
    int value =  dinput();
    if (value <= 0)
    {
        puts("Не является целым положительным числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double finput(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double fpositiveinput(void)
{
    double value = finput();
    if (value <= DBL_EPSILON)
    {
        puts("Не является положительным числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double GetElement(const double current, int k)
{
    return current * ((-1)/(pow(k, 2)+k));
}
