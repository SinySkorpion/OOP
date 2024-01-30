#include <iostream>
#include <string>
#include "Set.h"
#include "Test.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    // Использование шаблона Set для целых чисел
    Set<int> intSet;
    int inputInt;
    std::cout << "Введите целые числа (введите -1 чтобы закончить):\n";
    while (true) {
        std::cin >> inputInt;
        if (inputInt == -1) break;
        intSet.insert(inputInt);
    }
    intSet.print();

    // Использование шаблона Set для чисел с плавающей точкой
    Set<double> doubleSet;
    double inputDouble;
    std::cout << "Введите числа с плавающей точкой (введите -1 чтобы закончить):\n";
    while (true) {
        std::cin >> inputDouble;
        if (inputDouble == -1) break;
        doubleSet.insert(inputDouble);
    }
    doubleSet.print();

    // Использование шаблона Set для строк
    Set<std::string> stringSet;
    std::string inputString;
    std::cout << "Введите строки (введите \"-1\" чтобы закончить):\n";
    while (true) {
        std::cin >> inputString;
        if (inputString == "-1") break;
        stringSet.insert(inputString);
    }
    stringSet.print();

    /// Генерация исключения при доступе по индексу в Vect
    Vect<int> intVect;
    intVect.push_back(1);
    intVect.push_back(2);
    intVect.push_back(3);

    try {
        int value = intVect[3];
        std::cout << "Значение по индексу 3: " << value << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Перехваченное исключение: " << e.what() << std::endl;
    }

    testIntegerSet();
    testDoubleSet();
    testStringSet();

    return 0;
}