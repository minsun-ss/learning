# Given an array of integers, find the first missing positive integer in linear time and
# constant space. In other words, find the lowest positive integer that does not exist in
# the array. The array can contain duplicates and negative numbers as well.

# For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

# You can modify the input array in-place.

# Not so sure if this is the most efficient way to go.

A = [3, 4, -1, 1]
# answer is 2

for i in range(1,len(A)+2):
    if i not in A:
        print(i)