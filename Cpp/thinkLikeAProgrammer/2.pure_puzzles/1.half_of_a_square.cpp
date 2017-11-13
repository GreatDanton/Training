// Write a program that uses only two output statments, cout << "#" and
// cout << "\n", to produce a pattern of hash symbols shaped like half of a
//  perfect 5x5 square (or a right triangle)
/*

#####
####
###
##
#

*/
#include <iostream>

int main() {
    for (int row = 0; row < 5; row++) {
        int times = 5 - row;

        for (int hashNum = 0; hashNum < times; hashNum++) {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}