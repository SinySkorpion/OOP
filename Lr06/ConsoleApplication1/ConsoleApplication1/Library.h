#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    // Функция добавления новой книги
    void addBook(const Book& book);

    // Функция удаления книги по названию
    void removeBook(const std::string& title);

    // Функция отображения всех книг, отсортированных по авторам
    void displayByAuthor() const;

    // Функция отображения всех книг, отсортированных по годам
    void displayByYear() const;

    // Метод для получения списка книг
    const std::vector<Book>& getBooks() const {
        return books;
    }
};

#endif // LIBRARY_H