#include "vigenere.h"
#include <iostream>
#include <cctype>

// Constructor
Vigenere::Vigenere(std::string key) : key(key) {}

// Destructor
Vigenere::~Vigenere() {}

// Helper to repeat the key to match the message length
std::string Vigenere::repeatKey(const std::string& msg) const {
    std::string repeatedKey;
    int msgLen = msg.size();
    int keyLen = key.size();

    for (int i = 0; i < msgLen; i++) {
        repeatedKey += key[i % keyLen];
    }
    return repeatedKey;
}

// Helper to shift a character in the alphabet
char Vigenere::shiftChar(char c, int shift) const {
    return 'A' + (c - 'A' + shift + 26) % 26;
}

// Encrypt function
std::string Vigenere::encrypt(std::string msg) {
    std::string repeatedKey = repeatKey(msg);
    std::string encryptedMsg;

    for (size_t i = 0; i < msg.size(); i++) {
        if (isalpha(msg[i])) {
            encryptedMsg += shiftChar(msg[i], repeatedKey[i] - 'A');
        } else {
            encryptedMsg += msg[i]; // Keep non-alphabetic characters
        }
    }

    return encryptedMsg;
}

// Decrypt function
std::string Vigenere::decrypt(std::string msg) {
    std::string repeatedKey = repeatKey(msg);
    std::string decryptedMsg;

    for (size_t i = 0; i < msg.size(); i++) {
        if (isalpha(msg[i])) {
            decryptedMsg += shiftChar(msg[i], -(repeatedKey[i] - 'A'));
        } else {
            decryptedMsg += msg[i]; // Keep non-alphabetic characters
        }
    }

    return decryptedMsg;
}

// Check if encryption is valid
bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMessage) {
    return decrypt(encryptedMsg) == decryptedMessage;
}

// Update the key
void Vigenere::setKey(std::string key) {
    this->key = key;
}


int main() {
    // Create a Vigenère cipher object with a key
    std::string key = "HJK";  // Use a simple key for testing
    Vigenere cipher(key);
    
    // Define a message to encrypt
    std::string message = "WAR";
    
    // Encrypt the message
    std::string encryptedMessage = cipher.encrypt(message);
    
    // Output the original and encrypted message
    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
    
    // Decrypt the message to check the reverse process
    std::string decryptedMessage = cipher.decrypt(encryptedMessage);
    
    // Output the decrypted message to verify it matches the original
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    // Check if the encryption and decryption worked correctly
    if (decryptedMessage == message) {
        std::cout << "Encryption and Decryption are working correctly!" << std::endl;
    } else {
        std::cout << "Something went wrong in the encryption/decryption process." << std::endl;
    }
    
    return 0;
}