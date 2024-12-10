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
 * @brief создает массив
 * @param n длина массива
 * @return указатель на первый элемент массива
 */
int* CreateArray(const int n);

/**
 * @brief заполняет массив случайными целыми числами
 * @param array массив
 * @param n длина массива
 * @param max максимальное значение числа в массиве
 * @param min минимальное значение числа в массиве
 */
void FillRandom(int* array, const int n, const int max, const int min);

/**
 * @brief заполняет массив целыми числами, которые ввел пользователь
 * @param array массив
 * @param n длина массива
 */
void FillManually(int* array, const int n);

/**
 * @brief выводит массив на экран
 * @param array массив
 * @param n длина массива
 */
void PrintArray(int* array, const int n);

/**
  @brief Вычисляет произведение четных элементов массива
  @param array указатель на массив
  @param n количество элементов
  @return произведение четных элементов
 */
int ProductOfEven(int* array, const int n);

/**
  @brief Заменяет элементы массива с нечетными индексами на квадраты индексов
  @param array указатель на массив
  @param n количество элементов
 */
int* ReplaceIndexWithSquares(int* array,const int n);

/**
  @brief Проверяет наличие положительных элементов, делящихся на k с остатком 2
  @param array указатель на массив
  @param n количество элементов
  @param k значение для проверки
  @return true, если такие элементы есть, и false, если нет
 */
bool HasPositive(int* array, const int n, const int k);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите количество элементов n массива:");
    const int n = DPositiveInput();
    int* array = CreateArray(n);
    printf("Способ заполнения массива\n%d-Рандомные числа\n%d-Вручную\n",RANDOM, MANUAL);
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
                exit(EXIT_FAILURE);
            }
            FillRandom(array, n, max, min);
            break;
        case MANUAL:
            FillManually(array, n);
            break;
        default:
            puts("Такой операции не существует");
            free(array);
            exit(EXIT_FAILURE);

    }
    puts("Содержимое массива: ");
    PrintArray(array, n);
    int product = ProductOfEven(array, n);
    if (product == 1)
    {
        puts("В массиве нет четных элементов");
    }
    else
    {
        printf("Произведение четных элементов: %d\n", product);
    }
    int* newarray = ReplaceIndexWithSquares(array, n);
    printf("Массив после замены элементов с нечетными индексами на квадраты индексов:");
    PrintArray(newarray, n);
    puts("Введите число k");
    int k = DPositiveInput();
    if (HasPositive(array, n, k))
    {
        printf("Найдены положительные элементы, делящиеся на %d с остатком 2",k);
    }else
    {
        printf("Положительные элементы, делящиеся на %d с остатком 2, не найдены", k);
    }
    free(array);
    free(newarray);
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

int* CreateArray(const int n)
{
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL)
    {
        puts("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    return array;
}

void FillRandom(int *array, const int n, const int max, const int min)
{
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % (max-min+1) + min;
    }
}

void FillManually(int *array, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("\nВведите элемент массива номер %zu\n", i+1);
        array[i] = DInput();
    }
}

void PrintArray(int *array, const int n)
{
    for (size_t i = 0; i < n; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int ProductOfEven(int* array, int n)
{
    int product = 1;
    int haseven = 0;
    for (size_t i = 0; i<n; i++)
    {
        if (array[i]%2 == 0)
        {
            product *= array[i];
            haseven = 1;
        }
    }
    if (haseven == 0)
    {
        return 1;
    }
    return product;
}

int* ReplaceIndexWithSquares(int* array, int n)
{
    int* newarray = CreateArray(n);
    for (size_t i = 0; i < n; i++)
    { 
        if(i%2 != 0)
        {
            newarray[i] = i*i;
        }
        else
        {
            newarray[i] = array[i];
        }
    }
    return newarray;   
}

bool HasPositive(int* array, int n, int k)
{
    for (size_t i = 0; i < n; i++) 
    {
        if (array[i] > 0 && array[i] % k == 2) 
        {
            return true;
        }
    }
    return false;
}