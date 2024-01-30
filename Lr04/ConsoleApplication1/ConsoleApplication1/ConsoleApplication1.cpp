// main.cpp 
#include "ZNAK.h" 
#include <algorithm> 
#include "UnitTest.h"

//#include <Windows.h>

int main() {
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    const int size = 8;
    ZNAK znaks[size];

    // Входные данные 
    int i = 0;
    while (i < size) {
        std::cout << "Введите данные о человек " << i + 1 << ":\n";
        std::cin >> znaks[i];

        // Увеличивайте счетчик только в том случае, если ввод успешен. 
        if (std::cin) {
            ++i;
        }
        else {
            // Очистите флаг ошибки и отбросьте неверный ввод. 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный Ввод. Пожалуйста, попробуйте еще раз.\n";
        }
    }

    // Сортировка по дате рождения 
    std::sort(znaks, znaks + size, [](const ZNAK& a, const ZNAK& b) {
        return std::lexicographical_compare(a.getBirthdate(), a.getBirthdate() + 3, b.getBirthdate(), b.getBirthdate() + 3);
        });

    // Вывод отсортированных данных  
    std::cout << "\nСортированные данные:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << znaks[i];
    }

    // Поиск по знаку зодиака 
    std::string searchSign;
    std::cout << "\nВведите знак зодиака для поиска: ";
    std::cin >> searchSign;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (znaks[i].getZodiacSign() == searchSign) {
            found = true;
            std::cout << "\nЛюди, рожденные под " << searchSign << ":\n";
            std::cout << znaks[i];
        }
    }

    if (!found) {
        std::cout << "Не найдено людей со знаком Зодиака: " << searchSign << "\n";
    }

    return 0;

    testZNAK();
}