#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include<time.h>

/**
 * @brief перечисление вариантов заполнения массива
 * @param RANDOM заполнение массива случайными числами
 * @param MANUAL заполнение массива вручную
 */
typedef enum
{
    RANDOM = 1,
    MANUAL = 2
}FillMethod;


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
  @brief Вычисляет произведение четных элементов массива
  @param array указатель на массив
  @param n количество элементов
  @return произведение четных элементов
 */
int ProductOfEven(int* array, int n);

/**
  @brief Заменяет элементы массива с нечетными индексами на квадраты индексов
  @param array указатель на массив
  @param n количество элементов
 */
void ReplaceIndexWithSquares(int* array, int n);

/**
  @brief Проверяет наличие положительных элементов, делящихся на k с остатком 2
  @param array указатель на массив
  @param n количество элементов
  @param k значение для проверки
  @return true, если такие элементы есть, и false, если нет
 */
bool HasPositive(int* array, int n, int k);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите количество элементов n массива:");
    const int n = DPositiveInput();
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL)
    {
        puts("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    puts("Способ заполнения массива\n1.Рандомные числа\n2.Вручную");
    int choice = DPositiveInput();

    switch(choice)
    {
        case RANDOM:
            puts("Введите минимальное значение элементов массива");
            const int min = DInput();
            puts("Введите максимальное значение эдементов массива");
            const int max = DInput();
            if (min>max)
            {
                puts("Неверное значение промежутка");
                return 1;
            }
            srand(time(NULL));
            for (int i = 0; i < n-1; i++)
            {
                array[i] = rand() % (max-min+1) + min;
            }
            break;
        case MANUAL:
            for (int i = 0; i < n; i++)
            {
                printf("\nВведите элемент массива номер %d\n", i+1);
                array[i] = DInput();
            }
            break;
        default:
            puts("Такой операции не существует");
            exit(EXIT_FAILURE);

    }
    puts("Содержимое массива: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    int product = ProductOfEven(array, n);
    printf("Произведение четных элементов: %d\n", product);
    ReplaceIndexWithSquares(array, n);
    printf("Массив после замены элементов с нечетными индексами на квадраты индексов:");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    puts("Введите число k");
    int k = DPositiveInput();
    if (HasPositive(array, n, k))
    {
        printf("Найдены положительные элементы, делящиеся на %d с остатком 2",k);
    }else
    {
        printf("Положительные элементы, делящиеся на %d с остатком 2, не найдены", k);
    }
    return 0;
}


int DInput(void)
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        puts("Не является целым числом");
        exit(EXIT_FAILURE);

    }
    return value;
}

int DPositiveInput(void)
{
    int value = DInput();
    if(value <= 0)
    {
        puts("Не является целым положительным числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

int ProductOfEven(int* array, int n)
{
    int product = 1;
    int haseven = 0;
    for (int i = 0; i<n; i++)
    {
        if (array[i]%2 == 0)
        {
            product *= array[i];
            haseven = 1;
        }
    }
    if (haseven == 0)
    {
        puts("Нет четных элементов");
        return 1;
    }
    return product;
}

void ReplaceIndexWithSquares(int* array, int n)
{
    for (int i = 1; i < n; i += 2)
    { 
        array[i] = i*i;
    }
}

bool HasPositive(int* array, int n, int k)
{
    for (int i = 0; i < n; i++) 
    {
        if (array[i] > 0 && array[i] % k == 2) 
        {
            return true;
        }
    }
    return false;
}
