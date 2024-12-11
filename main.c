#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <time.h>

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
 * @brief находит максимальный модуль в массиве
 * @param array указатель на массив
 * @param n длина массива
 * @return максимальный модуль
 */
int FindMaxAbs(int* array, int n);

/**
 * @brief заменяет предпоследний элемент максимальным модулем из массива
 * @param array указатель на массив
 * @param n длина массива
 * @return указатель на первый элемент массива с замененным элементом
 */
int* ReplacePenult(int* array, const int n);
/**
 * @brief вставляет элемент со значением К до и после всех элементов, заканчивающихся на цифру К
 * @param array указатель на массив
 * @param n длина массива
 * @param k заданное число 
 * @return указатель на первый элемент массива с добавленными К
 */
int* AddKInArray(int* array, const int n, const int k);
/**
 * @brief вычисляет, сколько элементов оканчиватся на число К
 * @param array указатель на массив
 * @param n длина массива
 * @param k заданное число
 * @return количество элементов оканчиватся на число К
 */
int HowManyK(int* array, const int n, const int k);

/**
 * @brief создает новый массив A
 * @param n длина массива
 * @param array указатель на массив D
 * @return массив A
 */
int* ArrayA(const int n, int* array);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите количество элементов n массива:");
    const int n = DPositiveInput();
    int* array = CreateArray(n);
    printf("Способ заполнения массива\n%d.Рандомные числа\n%d.Вручную\n", RANDOM, MANUAL);
    int choice = DPositiveInput();
    switch(choice)
    {
        case RANDOM:
            puts("Введите минимальное значение элементов массива");
            const int min = DInput();
            puts("Введите максимальное значение элементов массива"); 
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
            exit(EXIT_FAILURE);

    }
    puts("Содержимое массива: ");
    PrintArray(array, n);
    int* replacearray = ReplacePenult(array, n);
    puts("Массив после замены предпоследнего элемента: ");
    PrintArray(replacearray, n);
    puts("Введите значение k от 0 до 9");
    const int k = DPositiveInput();
    if (k < 0 || k > 9)
    {
        puts("Неверное значение k");
        exit(EXIT_FAILURE);
    }
    int* arraywithk = AddKInArray(array, n, k);
    puts("Новый массив с K: ");
    PrintArray(arraywithk, (n+(HowManyK(array, n, k)*2)));
    int* arrayA = ArrayA(n, array);
    puts("Массив А: ");
    PrintArray(arrayA, n);
    free(array);
    free(arraywithk);
    free(arrayA);
    free(replacearray);
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

int *CreateArray(const int n)
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

int FindMaxAbs(int* array, int n)
{
    int maxabs = abs(array[0]);
    for (size_t i = 1; i<n; i++)
    {
        if (abs(array[i]) > maxabs)
        {
            maxabs = abs(array[i]);
        }
    }
    return maxabs;
}

int* ReplacePenult(int* array, const int n)
{
    if (n<2)
    {
        puts("Недостаточно элементов для замены предпоследнего");
        exit(EXIT_FAILURE);
    }
    int* newarray = CreateArray(n);
    for (size_t i = 0; i < n; i++)
    {
        newarray[i] = array[i];
    }
    int maxabs = FindMaxAbs(array, n);
    newarray [n-2] = maxabs;
    return newarray;
}

int *AddKInArray(int *array, const int n, const int k)
{
    int* newarray = CreateArray(n+(HowManyK(array, n, k)*2));
    size_t newindex = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (abs(array[i]) % 10 == k) 
        {
            newarray[newindex] = k;
            newindex++;
            newarray[newindex] = array[i];
            newindex++;
            newarray[newindex] = k;
            newindex++;
        }
        else
        {
            newarray[newindex] = array[i];
            newindex++;
        }
    }
    return newarray;
}

int HowManyK(int *array, const int n, const int k)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(array[i])%10 == k)
        {
            count++;
        }
    }
    return count;
}

int* ArrayA(const int n, int* array)
{
   int* arrayA = CreateArray(n);
   for (size_t i = 0; i<n; i++)
   {
    if (i%2 == 0)
    {
        arrayA[i] = i*array[i]*array[i];
    }
    else
    {
        arrayA[i] = array[i]/(i-1);
    }
   }
   return arrayA;
}