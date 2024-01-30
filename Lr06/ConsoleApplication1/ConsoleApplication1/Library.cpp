#include "Library.h"
#include <algorithm>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(),
        [&title](const Book& book) { return book.getTitle() == title; }),
        books.end());
}

void Library::displayByAuthor() const {
    std::vector<Book> sortedBooks = books;
    std::sort(sortedBooks.begin(), sortedBooks.end(),
        [](const Book& book1, const Book& book2) { return book1.getAuthor() < book2.getAuthor(); });

    for (const auto& book : sortedBooks) {
        book.display();
    }
}

void Library::displayByYear() const {
    std::vector<Book> sortedBooks = books;
    std::sort(sortedBooks.begin(), sortedBooks.end(),
        [](const Book& book1, const Book& book2) { return book1.getYear() < book2.getYear(); });

    for (const auto& book : sortedBooks) {
        book.display();
    }
}