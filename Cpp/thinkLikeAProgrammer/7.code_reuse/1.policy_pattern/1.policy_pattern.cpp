/*
 * Problem 1: The first student
 *
 * At a particular school, each class has a designated "first student" who is
 * responsible for maintining order in the classroom if the teacher has to leave
 * the room. Originally, this title was bestowed upon the student with the
 * highest grade, but now some teachers think the first student should be the
 * student with the greatest seniority, which means the lowest studentID number,
 * as they are assigned sequentally. Another faction of teachers thinks the
 * first student tradition is silly and intends to protest by simply choosing
 * the student whose name appears first in the alphabetically class roll. Our
 * task is to modify the student collection class, adding a method to retrieve
 * the first student from the collection, while accomodating the selection
 * criteria of the various teacher groups.
 */

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

    // see results based on chosen policy
    Collection.setFirstStudentPolicy(higherGrade);
    std::cout << "First Student by highest grade: " << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl;

    Collection.setFirstStudentPolicy(lowerStudentNumber);
    std::cout << "First student by Lower student id" << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl;

    Collection.setFirstStudentPolicy(nameComesFirst);
    std::cout << "First student by name alphabetically" << std::endl;
    std::cout << Collection.firstStudent().name() << std::endl;

    return 0;
}