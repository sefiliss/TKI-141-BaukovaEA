#include "Node.h"

/**
 * @brief Конструктор узла
 * @param val Значение узла
 * @param nxt Указатель на следующий узел
 */
Node::Node(int val, Node* nxt) : value(val), next(nxt) {}