/*
 *   Exercise 3-2
 *
 *   Rewrite the code that finds the agent with the best monthly sales average
 *   so that it finds the agent with the highest median sales. As stated
 *   earlier, the median of a set of values is the "one in the middle," such
 *   that half of the other values are higher and half of the other values are
 *   lower. If there is an even number of values, the median is the simple
 *   average of the two values in the middle. For example, in the set
 *   10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9. The average of
 *   7 and 9 is 8, so 8 is the median.
 */

#include <algorithm>
#include <iostream>

bool sortAsc(const int &A, const int &B) { return A > B; }

double getMedian(int intArray[], int array_size) {
    std::sort(intArray, intArray + array_size, sortAsc);
    if (array_size % 2 == 0) {
        // grab the two middle values and calculate average
        int index = array_size / 2;
        double average = (intArray[index] + intArray[index + 1]) / 2;
        return average;
    }

    int index = array_size / 2;
    return intArray[index];
}

int main() {
    //
    //
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766,
         2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}};

    double highestMedian = 0.0;
    int bestAgentIndex = 0;

    for (int i = 0; i < NUM_AGENTS; i++) {
        double median = getMedian(sales[i], NUM_MONTHS);
        if (median > highestMedian) {
            highestMedian = median;
            bestAgentIndex = i;
        }
    }
    std::cout << "The best agent is agent with index: " << bestAgentIndex
              << " with monthly sales average of: " << highestMedian
              << std::endl;

    return 0;
}