#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    // ������� ���������� ����� �����
    void addBook(const Book& book);

    // ������� �������� ����� �� ��������
    void removeBook(const std::string& title);

    // ������� ����������� ���� ����, ��������������� �� �������
    void displayByAuthor() const;

    // ������� ����������� ���� ����, ��������������� �� �����
    void displayByYear() const;

    // ����� ��� ��������� ������ ����
    const std::vector<Book>& getBooks() const {
        return books;
    }
};

#endif // LIBRARY_H