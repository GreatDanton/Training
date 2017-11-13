# create permutations function based on pseudocode
# Heap's algorithm

import copy


# Heap's algorithm
# Input: array [1,2]
# Output: array of permutations [[1,2], [2, 1]]
def permutations(array):
    finalArr = []  # contains permutations
    n = len(array)

    c = []
    for i in range(n):
        c.append(0)

    finalArr.append(copy.copy(array))
    i = 0
    while i < n:
        if c[i] < i:
            if i % 2 == 0:
                array[0], array[i] = array[i], array[0]
            else:
                array[c[i]], array[i] = array[i], array[c[i]]
            finalArr.append(copy.copy(array))  # make shallow copy of array
            c[i] += 1
            i = 0
        else:
            c[i] = 0
            i += 1
    return (finalArr)


a = permutations([1, 2, 3])
print(a)