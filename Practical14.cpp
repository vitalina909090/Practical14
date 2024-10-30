#include <iostream>
#include <Windows.h>

using namespace std;

int change(const char* mas) {
    long numbers = 0;
    int max = 2147483647;

    bool minus = false;
    if (*mas == '-') {
        minus = true;
        mas++;
    }

    for (int i = 0; mas[i] != '\0'; i++) {
        if (mas[i] < '0' || mas[i] > '9') {
            throw 1;
        }

        if (numbers > (max - (mas[i] - '0')) / 10) {
            throw 2;
        }

        numbers = numbers * 10 + (mas[i] - '0');
    }

    if (minus) {
        return -static_cast<int>(numbers);
    }
    else {
        return static_cast<int>(numbers);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* mas1 = "-123456";
    const char* mas2 = "12345654634636536";
    const char* mas3 = "12кц36536";

    try {
        int number1 = change(mas1);
        cout << "Число з mas1: " << number1 << endl;
    }
    catch (int error) {
        if (error == 1) { cout << "Можна використовувати лише цифри" << endl; }
        else if (error == 2) { cout << "Число занадто велике" << endl; }
    }

    try {
        int number2 = change(mas2);
        cout << "Число з mas2: " << number2 << endl;
    }
    catch (int error) {
        if (error == 1) { cout << "Можна використовувати лише цифри" << endl; }
        else if (error == 2) { cout << "Число занадто велике" << endl; }
    }

    try {
        int number3 = change(mas3);
        cout << "Число з mas2: " << number3 << endl;
    }
    catch (int error) {
        if (error == 1) { cout << "Можна використовувати лише цифри" << endl; }
        else if (error == 2) { cout << "Число занадто велике" << endl; }
    }

    return 0;
}
