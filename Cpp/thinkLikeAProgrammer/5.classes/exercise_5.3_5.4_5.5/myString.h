#ifndef MYSTRING_H
#define MYSTRING_H

typedef char *arrayString;

class myString {
  public:
    // constructor
    myString();
    myString(const arrayString &s);
    // destructor
    ~myString();
    // copy constructor
    myString(const myString &original);
    // operator overload
    myString &operator=(const myString &rhs);
    char operator[](int index);
    void append(char c);
    char characterAt(int index);
    void displayString();
    void remove(int startPos, int numOfChars);

  private:
    arrayString _string;
    int length(const arrayString &s);
    arrayString copyString(arrayString s);
};

#endif