// ZNAK.cpp
#include "ZNAK.h"

// �����������
ZNAK::ZNAK() {}

ZNAK::ZNAK(std::string lastName, std::string firstName, std::string zodiacSign, int birthdate[3]) :
    lastName(lastName), firstName(firstName), zodiacSign(zodiacSign) {
    for (int i = 0; i < 3; ++i) {
        this->birthdate[i] = birthdate[i];
    }
}

// ������ �������
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

// ������������� ���������
std::istream& operator>>(std::istream& is, ZNAK& znak) {
    std::cout << "������� �������: ";
    is >> znak.lastName;
    std::cout << "������� ���: ";
    is >> znak.firstName;
    std::cout << "������� ���� �������: ";
    is >> znak.zodiacSign;
    std::cout << "������� ���� �������� (���� ����� ���): ";
    for (int i = 0; i < 3; ++i) {
        is >> znak.birthdate[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const ZNAK& znak) {
    os << "��� � �������: " << znak.firstName << " " << znak.lastName << "\n";
    os << "���� �������: " << znak.zodiacSign << "\n";
    os << "���� ��������: ";
    for (int i = 0; i < 3; ++i) {
        os << znak.birthdate[i] << " ";
    }
    os << "\n";
    return os;
}