// Source.cpp --brief statement of the project’s purpose
//CSIS 212-B01--Lab 5
//<Citations if necessary> --
/*  Sources - Websites I used to help me code were
* W3school.com
* stackoverflow.com
* geeksforgeeks.com
* tutorialspoint.com
* learn.microsoft.com
* cplusplus.com
* 
*/

#include "ProcessedMessage.h"
#include <iostream>
#include <fstream>
#include <cstring>


int displayMenu() {
    int option;
    std::cout << "\n";
    std::cout << "   Vigenere Cipher \n";
    std::cout << "\n";
    std::cout << "        Main Menu\n";
    std::cout << "\n";
    std::cout << " 1. Encrypt File\n";
    std::cout << " 2. Decrypt File\n";
    std::cout << " 3. Quit\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   Selection: ";
    std::cin >> option;
    return option;
}

void processFile(const std::string& fileName, ProcessedMessage& pm, bool encrypt) {
    char text[1000];
    std::ifstream file(fileName);

    if (file.is_open()) {
        file.getline(text, 1000);
        char* nextToken = nullptr;
        char* token = strtok_s(text, " ", &nextToken);

        while (token != nullptr) {
            if (encrypt)
                pm.encryptToken(token);
            else
                pm.decryptToken(token);

            token = strtok_s(nullptr, " ", &nextToken);
        }
    }
    else {
        std::cerr << "Error: Could not open file " << fileName << ". Please make sure the file exists.\n";
    }
}

int main() {
    
    std::cout << "Cody Hudnall -- Lab #5 - Vigerene Cipher \n";
    std::cout << "\n";

    int option;
    std::string key;

    std::cout << "Enter encryption/decryption key: ";
    std::cin >> key;

    ProcessedMessage pm(key);


// Encrypt file options

    do {
        option = displayMenu();
        if (option == 1) { 
            std::string fileName;
            std::cout << "Enter the name of the file to encrypt: ";
            std::cin >> fileName;
            processFile(fileName, pm, true);
            pm.outputText();
            pm.createFile("encrypted_output.txt");
            pm.clearWords();
        }

// Decrypt file options

        else if (option == 2) { 
            std::string fileName;
            std::cout << "Enter the name of the file to decrypt: ";
            std::cin >> fileName;
            processFile(fileName, pm, false);
            pm.outputText();
            pm.createFile("decrypted_output.txt");
            pm.clearWords();
        }
    } while (option != 3);

    return 0;
}
