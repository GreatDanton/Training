// In statistics, the mode of a set of values is the value that appears most
// often. Write code that processes an array of survey data, where survey takers
// have responded to a question with a number in the range 1-10, to determine
// the mode of the data set. For our purpose, if multiple modes exist, any may
// be chosen

#include <iostream>

int sortAscending(const void *voidA, const void *voidB) {
    int *intA = (int *)(voidA);
    int *intB = (int *)(voidB);
    return *intA - *intB;
}

void withSort() {
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    qsort(surveyData, ARRAY_SIZE, sizeof(int), sortAscending);

    for (int i : surveyData) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // start counting
    int mostFrequent = surveyData[0];
    int highestFrequency = 0;
    int currentFrequency = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        currentFrequency++;
        // if surveyData[i] is last occurence of value
        if (surveyData[i] == ARRAY_SIZE - 1 ||
            surveyData[i] != surveyData[i + 1]) {
            if (currentFrequency > highestFrequency) {
                highestFrequency = currentFrequency;
                mostFrequent = surveyData[i];
            }
            currentFrequency = 0;
        }
    }
    std::cout << "Most frequent: " << mostFrequent << std::endl;
    std::cout << "Highest frequency: " << highestFrequency << std::endl;
}

void withHistogram() {
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    // init histogram -> holding amount of each number
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    for (int i = 0; i < MAX_RESPONSE; i++) {
        histogram[i] = 0;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        histogram[surveyData[i] - 1]++;
    }

    int mostFrequent = 0;
    for (int i = 1; i < MAX_RESPONSE; i++) {
        if (histogram[i] > histogram[mostFrequent]) {
            mostFrequent = i;  // index of the array
        }
    }
    // mostFrequent is index of array
    std::cout << "Highest frequency: " << histogram[mostFrequent] << std::endl;
    mostFrequent++;  // this is the actual most frequent number
    std::cout << "Most Frequent: " << mostFrequent << std::endl;
}

int main() {
    //
    std::cout << "Solving with sort" << std::endl;
    withSort();

    std::cout << "\n";
    std::cout << "Solving with histogram" << std::endl;
    withHistogram();

    return 0;
}