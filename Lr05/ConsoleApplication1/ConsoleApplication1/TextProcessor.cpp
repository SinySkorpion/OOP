#include "TextProcessor.h"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <iostream>

void TextProcessor::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string sentence;
        while (std::getline(file, sentence)) {
            sentences.push_back(sentence);
        }
        file.close();
    }
}

void TextProcessor::printQuestions() const {
    for (const auto& sentence : sentences) {
        if (isQuestion(sentence)) {
            std::cout << sentence << '\n';
        }
    }
}

void TextProcessor::printExclamations() const {
    for (const auto& sentence : sentences) {
        if (isExclamation(sentence)) {
            std::cout << sentence << '\n';
        }
    }
}

bool TextProcessor::isQuestion(const std::string& sentence) const {
    return !sentence.empty() && sentence.find('?') != std::string::npos;
}

bool TextProcessor::isExclamation(const std::string& sentence) const {
    return !sentence.empty() && sentence.find('!') != std::string::npos;
}