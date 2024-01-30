#include <iostream>
#include "Student.h"
#include "StudentGroup.h"
#include <cassert>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    StudentGroup group;
    int choice;

    do {
        cout << "\nСписок студенческой группы:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Удалить студента\n";
        cout << "3. Найти студента\n";
        cout << "4. Сортировать по фамилии\n";
        cout << "5. Сортировка по дате рождения\n";
        cout << "6. Отображение информации о группе\n";
        cout << "0. Выход\n";
        cout << "Введите свой выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string firstName, lastName, dateOfBirth, phoneNumber;
            cout << "Введите имя: ";
            cin >> firstName;
            cout << "Введите фамилию: ";
            cin >> lastName;
            cout << "Введите дату рождения: ";
            cin >> dateOfBirth;
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            Student student(firstName, lastName, dateOfBirth, phoneNumber);
            group.AddStudent(student);
            break;
        }
        case 2: {
            string lastName;
            cout << "Введите фамилию для удаления: ";
            cin >> lastName;
            group.RemoveStudent(lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Введите фамилию, чтобы найти: ";
            cin >> lastName;
            Student foundStudent = group.FindStudentByLastName(lastName);
            if (foundStudent.GetFirstName() != "")
                foundStudent.DisplayStudentInfo();
            else
                cout << "Студент не найден\n";
            break;
        }
        case 4:
            group.SortByLastName();
            cout << "Отсортировано по фамилии\n";
            break;
        case 5:
            group.SortByDateOfBirth();
            cout << "Отсортировано по дате рождения\n";
            break;
        case 6:
            group.DisplayGroupInfo();
            break;
        case 0:
            cout << "До свидания!\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;

    /*Unit тест*/

    // Создаем студентов
    Student student1("John", "Doe", "1990-01-01", "1234567890");
    Student student2("Jane", "Smith", "1992-02-02", "9876543210");


    // Создаем группу и добавляем студентов
    group.AddStudent(student1);
    group.AddStudent(student2);


    // Проверяем, что студенты были добавлены
    assert(group.FindStudentByLastName("Doe").GetFirstName() == "John");
    assert(group.FindStudentByLastName("Smith").GetFirstName() == "Jane");


    // Удаляем студента по фамилии
    group.RemoveStudent("Doe");


    // Проверяем, что студент был удален
    assert(group.FindStudentByLastName("Doe").GetFirstName() == "");


    // Сортируем студентов по фамилии
    group.SortByLastName();


    // Проверяем, что студенты отсортированы по фамилии
    assert(group.FindStudentByLastName("Smith").GetFirstName() == "Jane");


    // Отображаем информацию о группе
    group.DisplayGroupInfo();


    return 0;
}