#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& firstName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber);

    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetDateOfBirth() const;
    std::string GetPhoneNumber() const;
    void DisplayStudentInfo() const;

private:
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string phoneNumber;
};

#endif