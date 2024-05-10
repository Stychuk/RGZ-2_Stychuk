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

// Функція для скорочення рядка до заданої довжини
string shortenString(string str, int length) {
    if (str.length() <= length) {
        return str;
    } else {
        return str.substr(0, length - 3) + "...";
    }
}

// Функція для скорочення всіх рядків у масиві до заданої довжини
string* shortenStrings(string* strings, int size, int length) {
    unordered_map<string, int> stringCount; // хешмапа для збереження кількості зустрічей кожного рядка
    string* shortenedStrings = new string[size]; // масив для збереження скорочених рядків

    for (int i = 0; i < size; ++i) {
    	// перевіряємо, чи цей рядок ще не зустрічався
        if (stringCount.find(strings[i]) == stringCount.end()) {
            stringCount[strings[i]] = 1;
            shortenedStrings[i] = shortenString(strings[i], length);
        } else { // якщо рядок вже зустрічався, додаємо до нього номер зустрічі
            string newStr = strings[i] + to_string(stringCount[strings[i]]);
            stringCount[strings[i]]++;
            shortenedStrings[i] = shortenString(newStr, length);
        }
    }

    return shortenedStrings;
}

int main() {
    int size, length;
    cout << "Введіть кількість рядків: ";
    cin >> size;
    cin.ignore();  // очищення символу нового рядка з буфера

    string* strings = new string[size]; // масив для зберігання рядків

    cout << "Введіть рядки:" << endl;
    for (int i = 0; i < size; ++i) {
        getline(cin, strings[i]);
    }

    cout << "Введіть довжину рядка: ";
    cin >> length;

    string* shortenedStrings = shortenStrings(strings, size, length); // виклик функції для скорочення рядків

    // виведення скорочених рядків у консоль
    cout << "Скорочені рядки:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Рядок " << i + 1 << ": " << shortenedStrings[i] << endl;
    }

    delete[] strings;
    delete[] shortenedStrings;

    return 0;
}
