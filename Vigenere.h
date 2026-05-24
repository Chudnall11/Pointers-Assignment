#ifndef VIGENERE_H
#define VIGENERE_H
#include <string>

// we make the Vigenere class using direct variable names from the instructions
class Vigenere {
  
public: Vigenere(std::string k);
      void setKey(std::string k);
      std::string encryptWord(const std::string& word);
      std::string decryptWord(const std::string& word);
      std::string getKey() const;

private: 
      std::string key;
      std::string toUpperCase(std::string str); //uppercase function mentioned in the instructions
};
#endif