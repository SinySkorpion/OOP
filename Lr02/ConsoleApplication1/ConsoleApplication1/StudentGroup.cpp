#include "StudentGroup.h"
#include <algorithm>

void StudentGroup::AddStudent(const Student& student) {
    students.push_back(student);
}

void StudentGroup::RemoveStudent(const std::string& lastName) {
    students.erase(
        std::remove_if(students.begin(), students.end(),
            [&lastName](const Student& s) { return s.GetLastName() == lastName; }),
        students.end());
}

Student StudentGroup::FindStudentByLastName(const std::string& lastName) const {
    for (const Student& student : students) {
        if (student.GetLastName() == lastName) {
            return student;
        }
    }
    // ¬ернуть пустого студента, если не найдено
    return Student("", "", "", "");
}

void StudentGroup::SortByLastName() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.GetLastName() < b.GetLastName();
        });
}

void StudentGroup::SortByDateOfBirth() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.GetDateOfBirth() < b.GetDateOfBirth();
        });
}

void StudentGroup::DisplayGroupInfo() const {
    for (const Student& student : students) {
        student.DisplayStudentInfo();
    }
}