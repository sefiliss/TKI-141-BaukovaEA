#pragma once
#include "Node.h"
#include <initializer_list>
#include <string>

/**
 * @brief Класс линейного односвязного списка целых чисел.
 */
class LinkedList {
private:
    Node* head; 
    size_t size; 

public:
    LinkedList(); 
    LinkedList(std::initializer_list<int> init); 
    LinkedList(const LinkedList& other); 
    LinkedList(LinkedList&& other) noexcept;
    ~LinkedList(); 

    LinkedList& operator=(const LinkedList& other); 
    LinkedList& operator=(LinkedList&& other) noexcept; 

    void insert(int value); 
    bool remove(int value); 
    bool contains(int value) const; 
    bool empty() const; 
    size_t length() const; 

    int& operator[](size_t index); 
    const int& operator[](size_t index) const;

    LinkedList& operator<<(int value); 
    LinkedList& operator>>(int& value); 

    std::string to_string() const; 

private:
    void clear(); 
    void copy_from(const LinkedList& other); 
};