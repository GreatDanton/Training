// draw
/*
#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#            #
*/

#include <iostream>

int main() {
    //
    for (int row = 1; row <= 8; row++) {
        int full = 2 * row;
        int empty = 14 - full;

        int firstSpace = row - 1;
        if (row > 4) {
            firstSpace = 8 - row;
            empty = 2 * row - 4;
            full = 14 - empty;
        }
        int middleSpace = empty - 2 * firstSpace;

        for (int fspace = 0; fspace < firstSpace; fspace++) {
            std::cout << " ";
        }

        for (int hashMark = 0; hashMark < full / 2; hashMark++) {
            std::cout << "#";
        }

        for (int mspace = 0; mspace < middleSpace; mspace++) {
            std::cout << " ";
        }

        for (int hashMark = 0; hashMark < full / 2; hashMark++) {
            std::cout << "#";
        }

        std::cout << "\n";
    }
    return 0;
}