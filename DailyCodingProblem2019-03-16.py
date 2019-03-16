# SOLVED... I think? I think this is O(n) but it only fits O(1) size in memory at
# any given time.

# Given a stream of elements too large to store in memory, pick a random element from the
# stream with uniform probability.

import random

A = [1, 2, 3, 4]

def get_random_location(A):
    rand_element_location = 0
    counter = 0

    for i in A:
        # for the first, and possibly only, element in the stream
        if counter == 0:
            counter += 1
            rand_element_location = 0
        else:
            rand_element_location = random.randint(0,counter)
            counter += 1
    return rand_element_location

location = get_random_location(A)
print(A[location])