//============================================================================
// Name        : program_rgz2.cpp
// Author      : Stychuk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Функція для скорочення рядка до заданої довжини
string shortenString(const string& str, int length) {
    if (length < 2) {
        cout << "Неможливо скоротити рядок до довжини менше 2" << endl;
        return str;
    }
    if (str.length() <= length) {
        return str;
    }
    // кількість крапок для скорочення
    string dots = "...";
    if (length == 3) {
        dots = "..";
    } else if (length == 2) {
        dots = ".";
    }
    // повернення скороченого рядка
    return str.substr(0, length - dots.length()) + dots;
}

int main() {
    // map для зберігання унікальних скорочених рядків
    map<string, int> strings;
    int size, length;
    cout << "Введіть кількість рядків: ";
    cin >> size;
    cout << "Введіть довжину рядка для скорочення: ";
    cin >> length;
    for (int i = 0; i < size; ++i) {
        string str;
        cout << "Введіть рядок: ";
        cin >> str;
        // скорочення рядка
        string j = shortenString(str, length);
        // якщо скорочений рядок вже існує, додаємо до нього номер
        if (strings.count(j) > 0) {
            strings[j]++;
            j += to_string(strings[j]);
        } else {
            strings[j] = 1;
        }
        cout << "Скорочений рядок: " << j << endl;
    }
    return 0;
}
