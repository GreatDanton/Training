#include "myString.h"
#include <iostream>

myString::myString() {
    _string = new char[1];
    _string[0] = 0;
}

myString::myString(const arrayString &s) {
    int len = length(s);
    _string = new char[len + 1];
    for (int i = 0; i < len; i++) {
        _string[i] = s[i];
    }
}

myString::~myString() {
    delete[] _string;
    _string = NULL;
}

int myString::length(const arrayString &s) {
    int count = 0;
    while (s[count] != 0) {
        count++;
    }
    return count;
}

void myString::append(const char c) {
    int oldLen = length(_string);
    arrayString newS = new char[oldLen + 2];
    for (int i = 0; i < oldLen; i++) {
        newS[i] = _string[i];
    }
    newS[oldLen] = c;
    newS[oldLen + 1] = 0;
    delete[] _string;
    _string = newS;
}

char myString::characterAt(int index) {
    if (index > 0) {
        return _string[index];
    }
    return '?';
}

void myString::displayString() { std::cout << _string << std::endl; }

arrayString myString::copyString(arrayString str) {
    int len = length(str);
    arrayString newS = new char[len];
    for (int i = 0; i < len; i++) {
        newS[i] = str[i];
    }
    return newS;
}

// copy constructor
myString::myString(const myString &original) {
    _string = copyString(original._string);
}

// operator overload (performs deep copy)
// if you are overloading operator always create copy constructor
myString &myString::operator=(const myString &rhs) {
    if (this != &rhs) {
        // avoid memory leak, remove _string from left hand side
        delete[] _string;
        _string = copyString(rhs._string);
    }
    return *this;
}

char myString::operator[](int index) {
    if (index > -1) {
        int len = length(_string);
        if (index > len) {
            return '?';
        }
        return _string[index];
    }
}