// UnitTest.cpp
#include <cassert>
#include <string.h>
#include "ZNAK.h"
#include "UnitTest.h"

using namespace std;

void testZNAK() {

    int date[]{ 1, 2, 1990 };

    //Тест конструктора
    ZNAK znak(string("Иванов"), string("Иван"), string("Овен"), date);

    //Тест методов доступа
    assert(znak.getLastName() == "Иванов");
    assert(znak.getFirstName() == "Иван");
    assert(znak.getZodiacSign() == "Овен");

    const int* birthdate = znak.getBirthdate();
    assert(birthdate[0] == 1);
    assert(birthdate[1] == 2);
    assert(birthdate[2] == 1990);

    // Если все тесты пройдены успелшно, выоводим сообщение об успешном завершении
    cout << "Все тесты пройдены!\n";
}

/*
int testMain() {
    // Вызов тестов
    testZNAK();

    return 0;
}
*/