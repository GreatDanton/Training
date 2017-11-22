#ifndef SC_ITERATOR_H
#define SC_ITERATOR_H

#include "studentCollection.h"
#include "studentRecord.h"

class scIterator {
  public:
    scIterator();
    scIterator(studentCollection::studentNode *initial);

    void advance();
    bool pastEnd();

    studentRecord student();

  private:
    studentCollection::studentNode *current;
};

#endif