#include "LInkedList.h"
#include <stdexcept>
#include <sstream>

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::LinkedList(std::initializer_list<int> init) : head(nullptr), size(0) {
    for (int val : init) insert(val);
}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr), size(0) {
    copy_from(other);
}

LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head), size(other.size) {
    other.head = nullptr;
    other.size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        size = other.size;
        other.head = nullptr;
        other.size = 0;
    }
    return *this;
}

void LinkedList::insert(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
    }
    else {
        Node* current = head;
        while (current->next) current = current->next;
        current->next = new_node;
    }
    ++size;
}

bool LinkedList::remove(int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->value == value) {
            if (prev)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            --size;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool LinkedList::contains(int value) const {
    Node* current = head;
    while (current) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

bool LinkedList::empty() const {
    return size == 0;
}

size_t LinkedList::length() const {
    return size;
}

int& LinkedList::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (size_t i = 0; i < index; ++i) current = current->next;
    return current->value;
}

const int& LinkedList::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (size_t i = 0; i < index; ++i) current = current->next;
    return current->value;
}

LinkedList& LinkedList::operator<<(int value) {
    insert(value);
    return *this;
}

LinkedList& LinkedList::operator>>(int& value) {
    if (!head) throw std::out_of_range("List is empty");
    Node* current = head;
    Node* prev = nullptr;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    value = current->value;
    if (prev)
        prev->next = nullptr;
    else
        head = nullptr;
    delete current;
    --size;
    return *this;
}

std::string LinkedList::to_string() const {
    std::ostringstream oss;
    Node* current = head;
    while (current) {
        oss << current->value;
        if (current->next) oss << " -> ";
        current = current->next;
    }
    return oss.str();
}

void LinkedList::clear() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    size = 0;
}

void LinkedList::copy_from(const LinkedList& other) {
    Node* current = other.head;
    while (current) {
        insert(current->value);
        current = current->next;
    }
}
