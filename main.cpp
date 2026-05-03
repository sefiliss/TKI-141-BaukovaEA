#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void inputVector(vector<int>& vec);
void printResult(const vector<int>& vec);

/**
 * @brief Функциональный объект для сравнения модулей чисел
 * 
 * @return true, если |a| < |b|.
 */
struct less_abs : public binary_function<int, int, bool> {
    bool operator()(int a, int b) const {
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

/**
 * @brief Вводит элементы вектора из одной строки
 * @param vec Ссылка на вектор для заполнения
 */
void inputVector(vector<int>& vec) {
    cout << "Введите элементы вектора через пробел: ";

    string line;
    getline(cin >> ws, line);

    istringstream iss(line);
    vec.assign(istream_iterator<int>(iss), istream_iterator<int>());
}

/**
 * @brief Находит первую соседнюю пару элементов, для которой |a| >= |b|
 * @param vec Исходный вектор
 */
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