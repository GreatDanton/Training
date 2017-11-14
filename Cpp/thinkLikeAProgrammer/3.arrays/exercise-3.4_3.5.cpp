/*
 *   Exercise 3-4
 *
 *   Here's a variation on the array of const values. Write a program for
 *   creating a substitution cipher problem. In a substitution cipher problem,
 *   all messages are made of uppercase letters and punctuation. The original
 *   message is called the plaintext, and you create the ciphertext by
 *   substituting each letter with another letter (for example, each C could
 *   become an X). For this problem, hard-code a const array of 26 char elements
 *   for the cipher, and have your program read a plaintext message and output
 *   the equivalent ciphertext.
 *
 *
 *
 *   Exercise 3-5
 *
 *   Have the previous program convert the ciphertext back to the plaintext to
 *   verify the encoding and decoding
 */
#include <algorithm>
#include <iostream>

const char cipher[26] = {'B', 'N', 'M', 'V', 'C', 'X', 'Y', 'A', 'S',
                         'D', 'K', 'L', 'J', 'H', 'G', 'F', 'T', 'R',
                         'E', 'W', 'Q', 'Z', 'U', 'I', 'O', 'P'};

const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

std::string decode(std::string ciphertext) {
    std::string plaintext;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (c == ' ') {
            plaintext += ' ';
        } else {
            int index =
                std::distance(cipher, std::find(cipher, cipher + 26, c));
            plaintext += alphabet[index];
        }
    }
    return plaintext;
}

int main() {
    std::cout << "Insert a message that will be encrypted: ";
    std::string plaintext;
    std::getline(std::cin, plaintext);

    std::string ciphertext;

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (c == ' ') {
            ciphertext += " ";
        } else {
            int index = plaintext[i] - 'A';
            ciphertext += cipher[index];
        }
    }
    std::cout << "\n";

    std::cout << "Encrypted message: " << std::endl;
    std::cout << ciphertext << std::endl;
    std::cout << "\n";

    std::string decryptedText = decode(ciphertext);
    std::cout << "Decrypted text" << std::endl;
    std::cout << decryptedText << std::endl;

    return 0;
}