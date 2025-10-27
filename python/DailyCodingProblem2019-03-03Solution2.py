# SOLVED

# Given an array of integers, return a new array such that each element at index i of the new array is the
# product of all the numbers in the original array except the one at i.

# For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
# If our input was [3, 2, 1], the expected output would be [2, 3, 6].

# Follow-up: what if you can't use division?

import numpy as np

A = [1, 2, 3, 4, 5]
# expected output would be [120,60,40,30,24]

R = [1] * len(A)
for i in range(len(A)):
    temp = [A[i]] * 4
    temp.insert(i,1)
    R = list(np.multiply(R,temp))

print(R)