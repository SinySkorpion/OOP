#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include <vector>

class TextProcessor {
public:
    void readFromFile(const std::string& filename);
    void printQuestions() const;
    void printExclamations() const;
    bool isQuestion(const std::string& sentence) const;
    bool isExclamation(const std::string& sentence) const;

    // Add a public method to access sentences vector
    const std::vector<std::string>& getSentences() const {
        return sentences;
    }

private:
    std::vector<std::string> sentences;
};

#endif // TEXTPROCESSOR_H