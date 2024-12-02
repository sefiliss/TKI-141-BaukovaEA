#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief считывает целое число
 * @return целое число
 */
int DInput(void);

/**
 * @brief считывает целое число и проверяет знак
 * @return целое положительное число
 */
int DPositiveInput(void);



/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите количество элементов n массива:");
    const int n = DPositiveInput();
}