#ifndef PROCESSEDMESSAGE_H
#define PROCESSEDMESSAGE_H

#include "Vigenere.h"
#include <string>
#include <vector>


// We make the processed message class
class ProcessedMessage {

    // Used exact same variable names as instructed
public:
    ProcessedMessage(std::string key);
    void encryptToken(char* token);
    void decryptToken(char* token);
    void outputText() const;
    void createFile(const std::string& fileName) const;
    void clearWords();
    int numberWordsInMessage() const;

private:
    std::vector<std::string> processedWords;
    Vigenere v;
};
#endif