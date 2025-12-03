#include <limits>
#include <stdexcept>
#include <iostream>
#include "IStreamGenerate.h"

int IStreamGenerate::generate() {
    int number = int_input("Input the number:");
    return number;
}

int IStreamGenerate::int_input(const std::string& message) {
    if (!message.empty()) {
        std::cout << message;
    }

    int value;
    in >> value;

    if (in.eof()) {
        throw std::runtime_error("End of input");
    }

    if (in.fail()) {
        throw std::invalid_argument("Invalid input: expected an integer");
    }

    char next = in.peek();
    if (next != std::char_traits<char>::eof() &&
        next != ' ' && next != '\t' && next != '\n') {
        throw std::invalid_argument("Invalid input: trailing characters after number");
    }

    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}
