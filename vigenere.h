/**
 * @file vigenere.h
 * @brief Header file containing the Vigenere cipher class implementation
 * @author Manoj Karvannan
 * @date November 21, 2024
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

/**
 * @brief A class implementing the Vigenère cipher encryption algorithm
 * @details The Vigenère cipher is a polyalphabetic substitution cipher that uses a keyword
 * to encrypt and decrypt messages. The algorithm works by using the keyword letters
 * to shift the message letters forward (for encryption) or backward (for decryption)
 * in the alphabet. If the keyword is shorter than the message, it is repeated as needed.
 * 
 * Example:
 * Key = "WAR", Message = "HELLO"
 * Extended Key = "WARWA"
 * Each letter in the message is shifted by the corresponding letter's position in the key
 */
class Vigenere {
public:
    /**
     * @brief Constructor that initializes the cipher with an encryption key
     * @param key The encryption key (must be uppercase letters only)
     * @details Creates a new Vigenere cipher object with the specified key.
     * The key will be used for both encryption and decryption operations.
     */
    Vigenere(std::string key);

    /**
     * @brief Destructor for the Vigenere class
     * @details Cleans up any resources used by the Vigenere object
     */
    ~Vigenere();

    /**
     * @brief Encrypts a message using the Vigenère cipher
     * @param msg The message to encrypt (must be uppercase letters)
     * @return The encrypted message in uppercase letters
     * @details Each letter in the message is shifted forward in the alphabet
     * by the position value of the corresponding letter in the key
     */
    std::string encrypt(std::string msg);

    /**
     * @brief Decrypts a message using the Vigenère cipher
     * @param msg The encrypted message to decrypt (must be uppercase letters)
     * @return The decrypted message in uppercase letters
     * @details Each letter in the encrypted message is shifted backward in the alphabet
     * by the position value of the corresponding letter in the key
     */
    std::string decrypt(std::string msg);

    /**
     * @brief Verifies if an encrypted message corresponds to a decrypted message
     * @param encryptedMsg The encrypted version of the message
     * @param decryptedMessage The decrypted version of the message
     * @return true if the encrypted message matches the decrypted message when decrypted,
     *         false otherwise
     * @details This function encrypts the decryptedMessage and compares it with
     * the provided encryptedMsg to verify the encryption/decryption process
     */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

    /**
     * @brief Changes the encryption/decryption key
     * @param key The new key to use (must be uppercase letters)
     * @details Updates the key used by the cipher for all subsequent
     * encryption and decryption operations
     */
    void setKey(std::string key);

private:
    std::string key; ///< The encryption/decryption key

    std::string repeatKey(const std::string& msg) const; // Helper to repeat the key to match the length of the message

    char shiftChar(char c, int shift) const; // Helper to shift a character forward/backward in the alphabet

};

#endif // VIGENERE_H