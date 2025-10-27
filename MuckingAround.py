from collections import Counter

A = [1,2,2,3,4,4,5,5,5,4]

minimum = [] # this will hold the minimum number of turns for each pip

for pip in range(1,7): # this represents pip face
    opposite_pip = 7-pip # find the opposite pip side
    pipturn = 0
    for i in A:
        if i == opposite_pip: # opposite pips require 2 turns
            pipturn = pipturn+2
        elif i != pip: # non opposite pips require 1 turn
            pipturn = pipturn+1
        else:
            pass
    minimum.append(pipturn) # adds number of pip turns to a list

min_pip_turns = min(minimum) # this finds the minimum number of turns
min_pip = minimum.index(min_pip_turns)+1 # this determines which pip it is
print(min_pip)
