/*
*   Problem: Variable-Length String Manipulation
*

*   Write heap-based implementations for three required string functions:
*
*   append - This function takes a string and a character and appends the
*   character to the end of the string.
*
*   concatenate - This function takes two strings and appends the characters
*   of the second string onto the first.
*
*   characterAt - This function takes a string and a number and returns the
*   character at that position in the string (with the first character in the
*   string numbered zero).
*
*   Write the code with the assumption that characterAt will be called
*   frequently while the other two functions will be called reletively seldom.
*   The relative efficiency of the operations should reflect the calling
*   frequency.
*/
#include <iostream>

typedef char *arrayString;

// return character in arrayString at index = position
char characterAt(arrayString s, int position) { return s[position]; }

int length(arrayString s) {
    int count = 0;
    while (s[count] != 0) {
        count++;
    }
    return count;
}

// appends character to string s
void append(arrayString &s, char c) {
    int oldLength = length(s);
    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++) {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void appendTester() {
    arrayString a = new char[5];  // dynamic allocation
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;
    append(a, '!');
    std::cout << a << "\n";
}

void concatenate(arrayString &s1, arrayString s2) {
    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    for (int i = 0; i < s1_OldLength; i++) {
        newS[i] = s1[i];
    }
    for (int i = 0; i < s2_Length; i++) {
        newS[s1_OldLength + i] = s2[i];
    }
    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;
}

void concatenateTester() {
    arrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;
    arrayString b = new char[1];
    b[0] = 0;
    concatenate(a, b);
    std::cout << a << "\n" << b << "\n";
    std::cout << (void *)a << "\n" << (void *)b << "\n";
}

int main() {
    //
    appendTester();  // ok
    concatenateTester();
    return 0;
}