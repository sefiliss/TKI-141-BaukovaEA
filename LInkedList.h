#pragma once
#include "Node.h"
#include <initializer_list>
#include <string>

/**
 * @brief Класс линейного односвязного списка целых чисел.
 * @param head Указатель на первый узел списка
 * @param size Количество элементов в списке
 */
class LinkedList {
private:
    Node* head; 
    size_t size; 

public:
     /**
     * @brief Конструктор по умолчанию
     */
    LinkedList(); 
    /**
     * @brief Конструктор из списка инициализации
     * @param init Список инициализации значений
     */
    LinkedList(std::initializer_list<int> init); 
    /**
     * @brief Конструктор копирования
     * @param other Ссылка на копируемый список
     */
    LinkedList(const LinkedList& other); 
    /**
     * @brief Конструктор перемещения
     * @param other ссылка на перемещаемый список
     */
    LinkedList(LinkedList&& other) noexcept;
    /**
     * @brief Деструктор
     */
    ~LinkedList(); 

    /**
     * @brief Оператор присваивания копированием
     * @param other Ссылка на копируемый список
     * @return Ссылка на текущий объект
     */
    LinkedList& operator=(const LinkedList& other); 
    /**
     * @brief Оператор присваивания перемещением
     * @param other ссылка на перемещаемый список
     * @return Ссылка на текущий объект
     */
    LinkedList& operator=(LinkedList&& other) noexcept; 

    /**
     * @brief Вставка элемента в конец списка
     * @param value Значение для вставки
     */
    void insert(int value); 
    /**
     * @brief Удаление первого вхождения значения
     * @param value Значение для удаления
     * @return true если элемент был найден и удален, false иначе
     */
    bool remove(int value); 
    /**
     * @brief Проверка наличия значения в списке
     * @param value Искомое значение
     * @return true если значение найдено, false иначе
     */
    bool contains(int value) const; 
    /**
     * @brief Проверка списка на пустоту
     * @return true если список пуст, false иначе
     */
    bool empty() const; 
    /**
     * @brief Получение количества элементов в списке
     * @return Количество элементов
     */
    size_t length() const; 

    /**
     * @brief Оператор доступа по индексу
     * @param index Индекс элемента
     * @return Ссылка на значение элемента
     * @throw std::out_of_range если индекс недопустим
     */
    int& operator[](size_t index); 
     /**
     * @brief Константный оператор доступа по индексу
     * @param index Индекс элемента
     * @return Константная ссылка на значение элемента
     * @throw std::out_of_range если индекс недопустим
     */
    const int& operator[](size_t index) const;

    /**
     * @brief Оператор вставки элемента
     * @param value Значение для вставки
     * @return Ссылка на текущий объект
     */
    LinkedList& operator<<(int value); 
    /**
     * @brief Оператор извлечения последнего элемента
     * @param value Ссылка для сохранения извлеченного значения
     * @return Ссылка на текущий объект
     * @throw std::out_of_range если список пуст
     */
    LinkedList& operator>>(int& value); 

     /**
     * @brief Преобразование списка в строку
     * @return Строковое представление списка
     */
    std::string to_string() const; 

private:
    /**
     * @brief Очистка списка
     */
    void clear(); 
    /**
     * @brief Вспомогательный метод копирования
     * @param other Ссылка на копируемый список
     */
    void copy_from(const LinkedList& other); 
};
