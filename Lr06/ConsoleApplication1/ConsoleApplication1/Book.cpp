#include "Book.h"
#include <iostream>

Book::Book(std::string author, std::string title, int year, int quantity)
    : author(std::move(author)), title(std::move(title)), year(year), quantity(quantity) {}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return year;
}

int Book::getQuantity() const {
    return quantity;
}

void Book::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Book::display() const {
    std::cout << "Автор: " << author << "\tНазвание: " << title << "\tГод: " << year << "\tКоличество: " << quantity << std::endl;
}