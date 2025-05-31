#pragma once

/**
 * @brief Структура узла односвязного списка.
 * @param value Целочисленное значение, хранящееся в узле
 * @param next Указатель на следующий узел в списке
 */
struct Node {
    int value; 
    Node* next; 

    /**
     * @brief Конструктор узла.
     * @param val Значение узла.
     * @param nxt Указатель на следующий узел (по умолчанию nullptr).
     */
    Node(int val, Node* nxt = nullptr);
};

