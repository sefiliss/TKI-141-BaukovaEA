#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;


/**
 * @brief Считывает элементы вектора из одной строки ввода
 * @param vec Ссылка на вектор для заполнения
 */
void inputVector(vector<int>& vec);

/**
 * @brief Находит и выводит первую соседнюю пару элементов, для которой |a| >= |b|
 * @param vec Исходный вектор
 */
void printResult(const vector<int>& vec);

/**
 * @brief Функциональный объект для сравнения модулей чисел
 */
struct less_abs : public binary_function<int, int, bool> {
    /**
     * @brief Сравнивает два числа по модулю
     * @param a Первое число
     * @param b Второе число
     * @return true, если |a| < |b|, иначе false
     */
    bool operator()(const int a, const int b) const {
        return abs(a) < abs(b);
    }
};

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    vector<int> V;

    inputVector(V);
    printResult(V);

    return 0;
}

void inputVector(vector<int>& vec) {
    cout << "Введите элементы вектора через пробел: ";

    string line;
    getline(cin >> ws, line);

    istringstream iss(line);
    vec.assign(istream_iterator<int>(iss), istream_iterator<int>());
}

void printResult(const vector<int>& vec) {
    if (vec.size() < 2) {
        cout << 0 << endl;
        return;
    }

    vector<int>::const_iterator it =
        adjacent_find(vec.begin(), vec.end(), not2(less_abs()));

    if (it != vec.end()) {
        cout << *it << " " << *(it + 1) << endl;
    } else {
        cout << 0 << endl;
    }
}