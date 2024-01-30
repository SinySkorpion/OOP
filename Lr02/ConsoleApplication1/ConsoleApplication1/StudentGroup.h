#ifndef STUDENT_GROUP_H
#define STUDENT_GROUP_H

#include "Student.h"
#include <vector>

class StudentGroup {
public:
    void AddStudent(const Student& student);
    void RemoveStudent(const std::string& lastName);
    Student FindStudentByLastName(const std::string& lastName) const;
    void SortByLastName();
    void SortByDateOfBirth();
    void DisplayGroupInfo() const;

private:
    std::vector<Student> students;
};

#endif