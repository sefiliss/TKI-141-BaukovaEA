#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

/**
 * @brief Подсчитывает количество положительных вещественных чисел в файле
 * @return int Количество положительных чисел, либо -1, если файл не удалось открыть
 */
int countPositiveNumbers();

/**
 * @brief Вызывает функцию подсчета положительных вещественных чисел
 * в файле name.txt и выводит результат на экран.
 * @return int 0 при успешном завершении программы
 */
int main() {
    int positive_count = countPositiveNumbers();
    
    if (positive_count != -1) {
        std::cout << "Количество положительных чисел: "
                  << positive_count << std::endl;
    }
    
    return 0;
}

int countPositiveNumbers() {
    /**
     * @brief Открывает текстовый файл name.txt
     */
    std::ifstream file("name.txt");
    
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл name.txt" << std::endl;
        return -1;
    }
    
    /**
     * @brief Подсчет положительных чисел в файле
     */
    int count = std::count_if(
        std::istream_iterator<double>(file),
        std::istream_iterator<double>(),
        [](double number) {
            return number > 0;
        }
    );
    
    return count;
}