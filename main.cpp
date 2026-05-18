#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

/**
 * @brief Вводит элементы вектора с клавиатуры
 * @param vec Ссылка на вектор для заполнения
 * @param name Имя вектора
 */
void inputVector(vector<int>& vec, const string& name);


/**
 * @brief Выводит содержимое вектора на экран
 * @param vec Константная ссылка на вектор
 */
void printVector(const vector<int>& vec);

/**
 * @brief Подсчитывает количество векторов Vi, содержащих все элементы V0
 * @param V0 Исходный вектор
 * @param vectors Набор векторов V1, ..., VN
 * @return Количество подходящих векторов
 */
int countMatchingVectors(const vector<int>& V0, const vector<vector<int>>& vectors);

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    vector<int> V0;
    vector<vector<int>> vectors;
    int N;
    
    inputVector(V0, "V0");

    cout << "Введите количество векторов N (> 0): ";
    cin >> N;
    cin.ignore();
    
    if (N <= 0) {
        cout << "Количество векторов должно быть больше 0" << endl;
        return 0;
    }

    vectors.resize(N);
    for (size_t i = 0; i < N; i++) {
        inputVector(vectors[i], "V" + to_string(i + 1));
    }
    
    cout << "\nВектор V0: ";
    printVector(V0);
    
    for (size_t i = 0; i < N; i++) {
        cout << "Вектор V" << i + 1 << ": ";
        printVector(vectors[i]);
    }
   
    int result = countMatchingVectors(V0, vectors);
    
    cout << "\nКоличество векторов Vi, содержащих все элементы V0: "
         << result << endl;
    
    return 0;
}

void inputVector(vector<int>& vec, const string& name) {
    cout << "Введите вектор " << name << ": ";
    
    string line;
    getline(cin, line);
    istringstream iss(line);
    vec.assign(istream_iterator<int>(iss), istream_iterator<int>());
}

void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "пуст" << endl;
        return;
    }
    
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int countMatchingVectors(const vector<int>& V0, const vector<vector<int>>& vectors) {
    int count = 0;
    
    set<int> setV0(V0.begin(), V0.end());
 
    for (const vector<int>& currentVector : vectors) {
        set<int> currentSet(currentVector.begin(), currentVector.end());
        
        if (includes(currentSet.begin(), currentSet.end(),
                     setV0.begin(), setV0.end())) {
            count++;
        }
    }
    
    return count;
}