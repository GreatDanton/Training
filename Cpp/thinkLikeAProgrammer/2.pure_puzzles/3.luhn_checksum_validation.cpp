// The Luhn formula is a widely used system for validating identification
// numbers. Using the original number, double the value of every other digit.
// Then add the values of the individual digits together (if a doubled value now
// has two digits, add the digits individually). The indentification number is
// valid if the sum is divisible by 10.
//
// Write a program that takes an identification number of arbitrary length and
// determinese whether the number is valid under the Lugn formula. The program
// must process each character before reading the next one.
//

#include <iostream>

int doubleDigitValue(int digit) {
    digit *= 2;
    if (digit < 10) {
        return digit;
    }

    int leftover = digit % 10;
    return 1 + leftover;
}

int main() {
    char digit;
    int position = 1;
    std::cout << "Enter a number: ";
    int evenLengthChecksum = 0;
    int oddLengthChecksum = 0;

    digit = std::cin.get();
    while (digit != 10) {
        if (position % 2 == 0) {  // for odd numbers
            oddLengthChecksum += doubleDigitValue(digit - '0');
            evenLengthChecksum += digit - '0';
        } else {
            oddLengthChecksum += digit - '0';
            evenLengthChecksum += doubleDigitValue(digit - '0');
        }
        digit = std::cin.get();
        position++;
    }

    // even number
    int checksum = 0;
    if ((position - 1) % 2 == 0) {
        checksum = evenLengthChecksum;
    } else {
        checksum = oddLengthChecksum;
    }

    if (checksum % 10 == 0) {
        std::cout << "Entered number is valid" << std::endl;
    } else {
        std::cout << "Entered number is invalid" << std::endl;
    }
    return 0;
}