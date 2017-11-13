#include <iostream>

// 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
// should return: "Right? Yes!"

char punctuationChar(int number) {
    char outputCharacter;
    switch (number) {
        case 1:
            outputCharacter = '!';
            break;
        case 2:
            outputCharacter = '?';
            break;
        case 3:
            outputCharacter = ',';
            break;
        case 4:
            outputCharacter = '.';
            break;
        case 5:
            outputCharacter = ' ';
            break;
        case 6:
            outputCharacter = ';';
            break;
        case 7:
            outputCharacter = '"';
            break;
        case 8:
            outputCharacter = '\'';
            break;
    }

    return outputCharacter;
}

int main() {
    char outputChar;
    char digitChar;

    enum modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
    modeType mode = UPPERCASE;

    // read character by character and convert them to numbers
    do {
        digitChar = std::cin.get();
        int number = (digitChar - '0');
        digitChar = std::cin.get();
        while ((digitChar != 10) && (digitChar != ',')) {
            number = number * 10 + (digitChar - '0');
            digitChar = std::cin.get();
        }

        switch (mode) {
            case UPPERCASE:
                number = number % 27;
                outputChar = number + 'A' - 1;
                if (number == 0) {
                    mode = LOWERCASE;
                    continue;  // jump to the next iteration of loop
                }
                break;
            case LOWERCASE:
                number = number % 27;
                outputChar = number + 'a' - 1;
                if (number == 0) {
                    mode = PUNCTUATION;
                    continue;
                }
                break;
            case PUNCTUATION:
                number = number % 9;
                outputChar = punctuationChar(number);
                if (number == 0) {
                    mode = UPPERCASE;
                    continue;
                }
                break;
        }
        std::cout << outputChar;
    } while (digitChar != 10);

    std::cout << std::endl;

    return 0;
}