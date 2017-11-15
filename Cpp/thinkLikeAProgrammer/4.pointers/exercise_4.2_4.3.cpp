/*
 *   Exercise 4-2
 *
 *   For our dynamically allocated strings, create a function substring that
 *   takes three parameters: an arrayString, a starting position integer, and
 *   an integer length of characters. The function returns a pointer to a new
 *   dynamically allocated string array. This string array contains the
 *   characters in the original string, starting at the specified position
 *   for the specified length. The original string is unaffected by the
 *   operation. So if the original string abcdefg, the position was 3, and the
 *   length was 4, then the new string would contain cdef.
 *
 *
 *   Exercise 4-3
 *
 *   For our dynamically allocated strings, create a function replaceString that
 *   takes three parameters, each of type arrayString: source, target, and
 *   replaceText. The function replaces every occurence of target in source
 *   with replaceText. For example, if source points to an array containing
 *   abcdabee, target points to ab, and replaceText points to xyz, then when the
 *   function ends, source should point to an array containing xyzcdxyzee.
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

arrayString substring(const arrayString &s, int startPos, int length) {
    arrayString newArr = new char[length];
    startPos -= 1;  // we are removing one because arrays start at 0
    for (int i = 0; i < length; i++) {
        newArr[i] = s[startPos + i];
    }
    return newArr;
}

void substringTester() {
    std::cout << "#### Substring tester " << std::endl;
    arrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;

    arrayString arr = substring(a, 2, 3);
    std::cout << arr << std::endl;
    // cleaning memory
    delete[] arr;
    arr = NULL;
}

// checks if two strings are equal
bool equalString(const arrayString &s1, const arrayString &s2) {
    int s1Len = length(s1);
    int s2Len = length(s2);
    if (s1Len != s2Len) {
        return false;
    }
    for (int i = 0; i < s1Len; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

void replaceString(arrayString &source, arrayString &target,
                   arrayString &replaceText) {
    int sourceLen = length(source);
    int targetLen = length(target);
    arrayString newS = new char[sourceLen + 1]{0};

    for (int i = 0; i < sourceLen; i++) {
        if (characterAt(source, i) == target[0]) {
            // check if substring exists
            arrayString sub1 = substring(source, i + 1, targetLen);

            // replace sub1 with replaceText
            if (equalString(sub1, target)) {
                arrayString firstPart = substring(source, 1, i);
                arrayString secondPart =
                    substring(source, i + 1 + targetLen, sourceLen);

                concatenate(newS, firstPart);
                concatenate(newS, replaceText);
                concatenate(newS, secondPart);

                // rewrite source with new replaced data
                for (int i = 0; i < sourceLen; i++) {
                    source[i] = newS[i];
                }
                newS[0] = 0;
            }
        }
    }
    delete[] newS;
}

void replaceTextTester() {
    std::cout << "ReplaceTextTester" << std::endl;
    arrayString source = new char[9]{'a', 'b', 'c', 'd', 'a', 'b', 'e', 'e', 0};
    arrayString target = new char[3]{'a', 'b', 0};
    arrayString replaceText = new char[3]{'x', 'y', 0};

    replaceString(source, target, replaceText);
    std::cout << source << std::endl;
}

int main() {
    //
    appendTester();  // ok
    concatenateTester();
    substringTester();
    replaceTextTester();

    return 0;
}