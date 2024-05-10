//============================================================================
// Name        : program_rgz2.cpp
// Author      : Stychuk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>

using namespace std;

string shortenString(string str, int length) {
    if (str.length() <= length) {
        return str;
    } else {
        return str.substr(0, length - 3) + "...";
    }
}

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

    string* shortenedStrings = new string[size];

    for (int i = 0; i < size; ++i) {
    	shortenedStrings[i] = shortenString(strings[i], length);
    }

    delete[] strings;
    delete[] shortenedStrings;

    return 0;
}
