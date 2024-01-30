#include <iostream>
#include "TextProcessor.h"
#include "TextProcessorTest.h"

int main() {
    setlocale(LC_ALL, "Russian");

    TextProcessor processor;
    processor.readFromFile("input.txt");

    std::cout << "Вопросительные предложения:\n";
    processor.printQuestions();

    std::cout << "\nВосклицательные предложения:\n";
    processor.printExclamations();

    testTextProcessor();

    return 0;
}