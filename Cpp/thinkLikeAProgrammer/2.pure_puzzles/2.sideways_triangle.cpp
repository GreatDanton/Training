// write a program that uses only two output statements, cout << "#" and
// cout << "\n", to produce a pattern of hash symbols shaped like a sideways
// triangle

/*
#
##
###
####
###
##
#

*/

#include <iostream>

int main() {
    for (int row = 1; row < 8; row++) {
        int amount = 4 - abs(4 - row);
        for (int hashMark = 0; hashMark < amount; hashMark++) {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}