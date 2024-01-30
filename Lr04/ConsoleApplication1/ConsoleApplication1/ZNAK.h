// ZNAK.h 
#ifndef ZNAK_H 
#define ZNAK_H 

#include <iostream> 
#include <string> 

class ZNAK {
private:
    std::string lastName;
    std::string firstName;
    std::string zodiacSign;
    int birthdate[3];

public:
    // ����������� 
    ZNAK();
    ZNAK(std::string lastName, std::string firstName, std::string zodiacSign, int birthdate[3]);

    // ������ ������� 
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getZodiacSign() const;
    const int* getBirthdate() const; // Updated to const 

    // ������������� ��������� 
    friend std::istream& operator>>(std::istream& is, ZNAK& znak);
    friend std::ostream& operator<<(std::ostream& os, const ZNAK& znak);
};

#endif // ZNAK_H