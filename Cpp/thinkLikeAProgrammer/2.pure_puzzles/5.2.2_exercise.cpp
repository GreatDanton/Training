// draw
/*
   ##
  ####
 ######
########
########
 ######
  ####
   ##
*/

#include <iostream>

int main() {
    //
    for (int row = 1; row <= 8; row++) {
        int empty = abs(8 - 2 * row);
        if (row > 4) {
            empty -= 2;
        }
        int full = 8 - empty;

        for (int space = 0; space < empty / 2; space++) {
            std::cout << " ";
        }

        for (int hashMark = 0; hashMark < full; hashMark++) {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    return 0;
}