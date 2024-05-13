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
    if (length <= 2) {
        return "";
    }
    if (str.length() <= length) {
        return str;
    }
    // кількість крапок для скорочення
    string dots = "...";
    if (length == 4) {
        dots = "..";
    } else if (length == 3) {
        dots = ".";
    }
    // повернення скороченого рядка
    return str.substr(0, length - dots.length() - 1) + dots + str.back();
}

int main() {
    // map для зберігання унікальних скорочених рядків
    map<string, int> strings;
    int size, length;
    cout << "Введіть кількість рядків: ";
    cin >> size;
    cout << "Введіть довжину рядка для скорочення: ";
    cin >> length;
    if (length <= 2) {
    	cout << "Неможливо скоротити рядок." << endl;
    	system("pause");
    	return 0;
    }
    cin.ignore(); // очищення буфер вводу
    string* inputStrings = new string[size]; // динамічний масив рядків
    cout << "\nВведіть рядки:\n";
    for (int i = 0; i < size; ++i) {
    	getline(cin, inputStrings[i]); // заповнення масиву рядків
    	}
    cout << "\nСкорочені рядки: \n";
    for (int i = 0; i < size; ++i) {
    	// скорочення кожного рядка
    	string j = shortenString(inputStrings[i], length);
    	if (j == "") {
    		cout << "Неможливо скоротити рядок." << endl;
    		continue;
    	}
    	// якщо скорочений рядок вже існує, додаємо до нього номер
    	if (strings.count(j) > 0) {
    		strings[j]++;
    		j = shortenString(j + to_string(strings[j]), length);
    	} else {
    		strings[j] = 1;
    	}
    	cout << j << endl;
    }
    delete[] inputStrings;
    system("pause");
    return 0;
}
