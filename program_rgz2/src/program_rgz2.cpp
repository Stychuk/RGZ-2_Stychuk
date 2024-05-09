//============================================================================
// Name        : program_rgz2.cpp
// Author      : Stychuk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {
    int size, length;
    cout << "Введіть кількість рядків: ";
    cin >> size;
    cin.ignore();  // очищення символу нового рядка з буфера

    string* strings = new string[size];
    cout << "Введіть рядки:" << endl;
    for (int i = 0; i < size; ++i) {
        getline(cin, strings[i]);
    }

    cout << "Введіть довжину рядка: ";
    cin >> length;

    delete[] strings;

    return 0;
}
