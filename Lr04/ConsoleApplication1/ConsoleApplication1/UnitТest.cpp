// UnitTest.cpp
#include <cassert>
#include <string.h>
#include "ZNAK.h"
#include "UnitTest.h"

using namespace std;

void testZNAK() {

    int date[]{ 1, 2, 1990 };

    //���� ������������
    ZNAK znak(string("������"), string("����"), string("����"), date);

    //���� ������� �������
    assert(znak.getLastName() == "������");
    assert(znak.getFirstName() == "����");
    assert(znak.getZodiacSign() == "����");

    const int* birthdate = znak.getBirthdate();
    assert(birthdate[0] == 1);
    assert(birthdate[1] == 2);
    assert(birthdate[2] == 1990);

    // ���� ��� ����� �������� ��������, �������� ��������� �� �������� ����������
    cout << "��� ����� ��������!\n";
}

/*
int testMain() {
    // ����� ������
    testZNAK();

    return 0;
}
*/