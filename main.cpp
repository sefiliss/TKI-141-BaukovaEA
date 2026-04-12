#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void inputList(list<int>& L);
void displayListDirect(const list<int>& L);
void displayListReverse(const list<int>& L);

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    list<int> L;

    cout << "Работа со списком целых чисел" << endl;

    // Ввод списка
    inputList(L);

    // Вывод списка в исходном порядке
    cout << "\nЭлементы списка в исходном порядке: ";
    displayListDirect(L);

    // Вывод списка в обратном порядке
    cout << "Элементы списка в обратном порядке: ";
    displayListReverse(L);

    return 0;
}

/**
 * @brief Вводит элементы списка
 * @param L Ссылка на список
 */
void inputList(list<int>& L) {
    cout << "Введите целые числа через пробел." << endl;

    L = list<int>(
        istream_iterator<int>(cin),
        istream_iterator<int>()
    );
}

/**
 * @brief Выводит элементы списка в исходном порядке
 * @param L Константная ссылка на список
 * @details Используется алгоритм copy и итератор ostream_iterator<int>.
 */
void displayListDirect(const list<int>& L) {
    copy(
        L.begin(),
        L.end(),
        ostream_iterator<int>(cout, " ")
    );
    cout << endl;
}

/**
 * @brief Выводит элементы списка в обратном порядке
 * @param L Константная ссылка на список
 * @details Используется алгоритм copy, итератор ostream_iterator<int> и обратные итераторы rbegin() и rend().
 */
void displayListReverse(const list<int>& L) {
    copy(
        L.rbegin(),
        L.rend(),
        ostream_iterator<int>(cout, " ")
    );
    cout << endl;
}