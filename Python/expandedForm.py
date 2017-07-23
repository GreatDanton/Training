# Create expanded form of integer argument
def expanded_form(num):
    num_str = str(num)[::-1] # reverse a string
    arr = [] # create empty array
    for i, v in enumerate(num_str):
        number = int(v) * 10**(i)

        if number != 0:
            arr.append(number)

    arr.sort(reverse=True)
    print(' + '.join(str(x) for x in arr))


# expanded_form(70304) # 70000 + 300 + 4


# find unique number in given array
def find_uniq(arr):
    nums = {}
    for i in arr:
        if i in nums: # check if i exists
            nums[i] += 1
        else:
            nums[i] = 1

    for i, v in nums.items():
        if v == 1:
            return i


# print(find_uniq([1,1,1,0,2,2])) # 0


# Tribonnaci - like fibonacci but summing last 3 instead of 2
# signature - first three numbers
# n - return first n items from tribonnaci sequence
def tribonnaci(signature, n):
    while len(signature) < n:
        signature.append(sum(signature[-3:]))
    return signature[:n]

t = tribonnaci([1,1,1], 10)
print(t)


# count characters in your string and returns dictionary
def count(string):
    counter = {}
    for char in string:
        if char in counter:
            counter[char] += 1
        else:
            counter[char] = 1
    return(counter)
print(count("ABCDA"))