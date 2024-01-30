// ZNAK.cpp
#include "ZNAK.h"

// Констурктор
ZNAK::ZNAK() {}

ZNAK::ZNAK(std::string lastName, std::string firstName, std::string zodiacSign, int birthdate[3]) :
    lastName(lastName), firstName(firstName), zodiacSign(zodiacSign) {
    for (int i = 0; i < 3; ++i) {
        this->birthdate[i] = birthdate[i];
    }
}

// Методы доступа
std::string ZNAK::getLastName() const {
    return lastName;
}

std::string ZNAK::getFirstName() const {
    return firstName;
}

std::string ZNAK::getZodiacSign() const {
    return zodiacSign;
}

const int* ZNAK::getBirthdate() const {
    return birthdate;
}

// Перегруженные операторы
std::istream& operator>>(std::istream& is, ZNAK& znak) {
    std::cout << "Введите фамилию: ";
    is >> znak.lastName;
    std::cout << "Введите имя: ";
    is >> znak.firstName;
    std::cout << "Введите знак зодиака: ";
    is >> znak.zodiacSign;
    std::cout << "Введите дату рождения (день месяц год): ";
    for (int i = 0; i < 3; ++i) {
        is >> znak.birthdate[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const ZNAK& znak) {
    os << "Имя и Фамилия: " << znak.firstName << " " << znak.lastName << "\n";
    os << "Знак зодиака: " << znak.zodiacSign << "\n";
    os << "Дата рождения: ";
    for (int i = 0; i < 3; ++i) {
        os << znak.birthdate[i] << " ";
    }
    os << "\n";
    return os;
}