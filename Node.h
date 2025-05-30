#pragma once

/**
 * @brief Структура узла односвязного списка.
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
