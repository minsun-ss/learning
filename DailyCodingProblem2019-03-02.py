# SOLVED
#Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
# For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
# Bonus: Can you do this in one pass?

A = [10, 10, 15, 3, 7]
k = 20

dict = {}
is_pair = -1

for i in A:
    kpair = k - i  # determine pair it has to match
    if (kpair in dict) and (dict[kpair] == 1):
        is_pair = 1
        break
    # if no match, hash i - has to be done afterward just in case there are 2 of the same # that add up
    # to k
    dict[i] = 1  

if is_pair == 1:
    print("There's a pair")
else:
    print("There is no pair")