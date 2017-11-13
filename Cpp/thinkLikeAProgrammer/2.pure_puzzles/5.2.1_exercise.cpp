// draw:
/*
########
 ######
  ####
   ##
*/

#include <iostream>

int main() {
    //
    for (int row = 0; row < 4; row++) {
        for (int space = 0; space < row; space++) {
            std::cout << " ";
        }

        int num = 8 - row * 2;
        for (int hashMark = 0; hashMark < num; hashMark++) {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    return 0;
}