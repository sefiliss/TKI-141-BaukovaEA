#include <iostream>
#include "Person.h"

using namespace std;

int main(void) {
  string ln, fn, pn;
  cout << "Введите имя:";
  cin >> ln;
  cout << "Введите фамилию:";
  cin >> fn;
  cout << "Введите отчество:";
  cin >> pn;
  Person student(ln, fn, pn);
  student.Show();
  student.ShowFormal();
  return 0;
}