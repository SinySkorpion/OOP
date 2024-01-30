#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(const string& firstName, const string& lastName, const string& dateOfBirth, const string& phoneNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->dateOfBirth = dateOfBirth;
    this->phoneNumber = phoneNumber;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetDateOfBirth() const {
    return dateOfBirth;
}

string Student::GetPhoneNumber() const {
    return phoneNumber;
}

void Student::DisplayStudentInfo() const {
    cout << "\nИмя Фамилия: " << firstName << " " << lastName << endl;
    cout << "Дата рождения: " << dateOfBirth << endl;
    cout << "Номер телефона: " << phoneNumber << endl;
}