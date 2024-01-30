#include <cassert>
#include <iostream>
#include "TextProcessor.h"
#include "TextProcessorTest.h"

void testTextProcessor() {
    // Test case 1: Check if reading from a file works
    TextProcessor processor;
    processor.readFromFile("input.txt");
    assert(!processor.getSentences().empty());

    // Test case 2: Check if questions are correctly identified
    assert(processor.isQuestion("Is this a question?"));
    assert(!processor.isQuestion("This is not a question."));

    // Test case 3: Check if exclamations are correctly identified
    assert(processor.isExclamation("Wow!"));
    assert(!processor.isExclamation("This is not an exclamation."));
    
    std::cout << "All tests passed successfully!\n";
}

/*
int testMain() {
    testTextProcessor();
    return 0;
}
*/