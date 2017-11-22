/*
 * Problem 2: Efficient Traversal
 *
 * A programming project will use your studentCollection class. The client code
 * needs the ability to traverse all of the students in the collection.
 * Obviously, to maintain information hiding, the client code cannot be given
 * direct acess to the list, but it's requirement that the traversals are
 * efficient.
 *
 */

#include "scIterator.h"
#include "studentCollection.h"
#include "studentRecord.h"
#include <iostream>

int main() {
    // create students
    studentRecord Tom(97, 1, "Tom");
    studentRecord Ana(98, 2, "Ana");
    studentRecord Sophie(100, 3, "Sophie");
    studentRecord Wrigley(93, 4, "Wrigley");

    // add students to collection
    studentCollection Collection;
    Collection.addRecord(Tom);
    Collection.addRecord(Ana);
    Collection.addRecord(Sophie);
    Collection.addRecord(Wrigley);

    scIterator iter;
    int gradeTotal = 0;
    int numRecords = 0;
    iter = Collection.firstItemIterator();

    while (!iter.pastEnd()) {
        numRecords++;
        gradeTotal += iter.student().grade();
        iter.advance();
    }
    double average = (double)gradeTotal / numRecords;
    std::cout << average << std::endl;

    return 0;
}