#include <stdio.h>
#include <math.h>

/**
* @brief функция расчета a
* @param x значение параметра x 
* @param y значение параметра y 
* @return возвращает a 
**/
double GetA(const double x, const double y);

/**
* @brief функция расчета b
* @param x значение параметра x 
* @param y значение параметра y 
* @param z значение параметра z
* @return возвращает b
**/
double GetB(const double x, const double y, const double z);

/**
* @brief точка входа в программу
* @return 0 в случае успеха 
**/
int main(void)
{
    const double x = 1.825;
    const double y = 18.225;
    const double z = -3.298;
    printf("Значение a = %lf\nЗначение b = %lf", GetA(x, y), GetB(x,y,z));
    return 0;

}

double GetA(const double x, const double y)
{
    return pow(x, (y / x)) - cbrt((y / x));
}

double GetB(const double x, const double y, const double z)
{
    return (y - x) + (((y - z) / (y - x)) / (3 + (pow(z,2)/5))) ;
}
