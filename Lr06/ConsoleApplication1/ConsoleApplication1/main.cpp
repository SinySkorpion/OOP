#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Test.h"
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1551);
    setlocale(LC_ALL, "Russian");

    Library library;
    int choice;

    do {
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Удалить книгу\n";
        std::cout << "3. Отобразить все книги по авторам\n";
        std::cout << "4. Отобразить все книги по годам\n";
        std::cout << "5. Выход\n";
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string author, title;
            int year, quantity;

            std::cout << "Введите автора: ";
            std::cin.ignore();
            std::getline(std::cin, author);

            std::cout << "Введите название: ";
            std::getline(std::cin, title);

            std::cout << "Введите год: ";
            std::cin >> year;

            std::cout << "Введите количество: ";
            std::cin >> quantity;

            Book newBook(author, title, year, quantity);
            library.addBook(newBook);
            break;
        }
        case 2: {
            std::string title;
            std::cout << "Введите название книги, которую нужно удалить: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            library.removeBook(title);
            break;
        }
        case 3:
            library.displayByAuthor();
            break;
        case 4:
            library.displayByYear();
            break;
        case 5:
            std::cout << "Существующая программа...\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, введите допустимый вариант.\n";
        }
    } while (choice != 5);

    runTests();

    return 0;
}