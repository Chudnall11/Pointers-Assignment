#include "Vigenere.h"
#include <string>
#include <cctype>


 // constructor
Vigenere::Vigenere(std::string k) {
    setKey(k);
}
// set and get keys
void Vigenere::setKey(std::string k) {
    key = toUpperCase(k);
}

std::string Vigenere::getKey() const {
    return key;
}

// to upper case function 
std::string Vigenere::toUpperCase(std::string str) {
    for (char& c : str) {
        c = std::toupper(c);
    }
    return str;
}

// encrypting word used straight from the instructions
std::string Vigenere::encryptWord(const std::string& word) {
    std::string output;
    for (int i = 0, j = 0; i < word.length(); ++i) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') c += 'A' - 'a';
        if (c < 'A' || c > 'Z') continue;
        output += (c + key[j] - 2 * 'A') % 26 + 'A';
        j = (j + 1) % key.length();
    }
    return output;
} 

// decrypting also pulled straight from the instructions
std::string Vigenere::decryptWord(const std::string& word) {
    std::string output;
    for (int i = 0, j = 0; i < word.length(); ++i) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') c += 'A' - 'a';
        if (c < 'A' || c > 'Z') continue;
        output += (c - key[j] + 26) % 26 + 'A'; 
        j = (j + 1) % key.length();
    }
    return output;
}
