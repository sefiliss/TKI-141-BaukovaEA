#include <iostream>
#include "LInkedList.h"

/** @brief Главная функция программы для демонстрации работы с односвязным списком.
 *  @return Код завершения программы.
 */
int main() {
    LinkedList list = { 1, 2, 3 };

    std::cout << "Добавляем 4 и 5 в список." << std::endl;
    list.insert(4);
    list << 5;

    int last;
    list >> last;
    std::cout << "Удалён последний элемент: " << last << std::endl;

    std::cout << "Список: " << list.to_string() << std::endl;
    std::cout << "Элемент с индексом 1: " << list[1] << std::endl;

    // Демонстрация операторов присваивания
    LinkedList copy;
    copy = list;
    std::cout << "Копия списка: " << copy.to_string() << std::endl;

    LinkedList moved;
    moved = std::move(copy);
    std::cout << "Список после перемещения: " << moved.to_string() << std::endl;
    std::cout << "Исходный список после перемещения (должен быть пустым): " << copy.to_string() << std::endl;

    return 0;
}
