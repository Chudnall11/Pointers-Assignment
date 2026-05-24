#include "ProcessedMessage.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

ProcessedMessage::ProcessedMessage(std::string key) : v(key) {}


void ProcessedMessage::createFile(const std::string& fileName) const {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const std::string& word : processedWords) {
            outFile << word << " ";
        }
        outFile.close();
    }
}
void ProcessedMessage::encryptToken(char* token) {
    std::string word(token);
    processedWords.push_back(v.encryptWord(word));
}

void ProcessedMessage::decryptToken(char* token) {
    std::string word(token);
    processedWords.push_back(v.decryptWord(word));
}
void ProcessedMessage::clearWords() {
    processedWords.clear();
}

int ProcessedMessage::numberWordsInMessage() const {
    return processedWords.size();
}
void ProcessedMessage::outputText() const {
    for (const std::string& word : processedWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

