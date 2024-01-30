#include "Test.h"
#include "Book.h"
#include "Library.h"
#include <cassert>

void testBook() {
    // Тест класса Book
    Book book("Автор", "Название", 2020, 5);
    assert(book.getAuthor() == "Автор");
    assert(book.getTitle() == "Название");
    assert(book.getYear() == 2020);
    assert(book.getQuantity() == 5);

    // Тест метода setQuantity
    book.setQuantity(10);
    assert(book.getQuantity() == 10);
}

void testLibrary() {
    // Тест класса Library
    Library library;

    // Тест метода addBook
    Book book1("Author1", "Title1", 2020, 5);
    library.addBook(book1);
    assert(library.getBooks().size() == 1);

    // Тест метода removeBook 
    library.removeBook("Title1");
    assert(library.getBooks().empty());

    // Тест методов displayByAuthor и displayByYear 
    Book book2("Author2", "Title2", 2018, 8);
    Book book3("Author3", "Title3", 2022, 3);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
}

void runTests() {
    testBook();
    testLibrary();
}