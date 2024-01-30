#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string author;
    std::string title;
    int year;
    int quantity;

public:
    Book(std::string author, std::string title, int year, int quantity);

    // Средства получения и настройки свойств книги
    std::string getAuthor() const;
    std::string getTitle() const;
    int getYear() const;
    int getQuantity() const;
    void setQuantity(int quantity);

    // Функция отображения сведений о книге
    void display() const;
};

#endif // BOOK_H