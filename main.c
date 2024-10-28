#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает целое число
 * @return целое число
 */
int Input(void);

/**
 * @brief считывает целое число и проверяет знак
 * @return целое число, если оно положительное
 */
int PositiveInput(void);
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
    const int start = 1;
    puts("Введите количество n");
    const int end = PositiveInput();
    const double zeroelement = 1;
    double current = zeroelement;
    double sum = zeroelement;
    for (int i = start; i <= end; i++)
    {
        current = GetElement(current, i);
        sum += current;
    }
    
    printf("%lf", sum);
    
    return 0;
}

int Input(void)
{
    int value = 0;
    if(scanf("%d", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

int PositiveInput(void)
{
    int value =  Input();
    if (value <= 0)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double GetElement(const double current, int k)
{
    return current * ((-1)/(pow(k, 2)+k));
}
