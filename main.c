#include <stdio.h>
/**
 * @brief рассчитывает силу тяжести
 * @param massa масса мешка
 * @param g ускорение свободного падения
 * @return силу тяжести
 */
double GetF(const double massa, const double g);

/**
 * @brief рассчитывает вес мешка
 * @param mass масса мешка
 * @param g ускорение свободного падения
 * @return вес мешка
 */
double GetW(const double massa, const double g);

/**
 * @brief считывает вещественное число
 * @return возврашает вещественное число
 */
double Input(void);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    puts("Введите массу мешка");
    const double g = 9.81;
    const double massa = Input();
    printf("Сила тяжести = %lf\nВес мешка = %lf", GetF(massa, g), GetW(massa, g));
    return 0;
}

double GetF(const double massa, const double g)
{
    return massa * g;
}

double GetW(const double massa, const double g)
{
    return massa * g;
}

double Input(void)
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;

}
