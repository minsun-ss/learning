A = [2,3,4,1,5]
# bulb should shine by the time 3 is hit

# basically a light only turns on if the first N elements in the set also contains 1 to N
shine = 0 # counter for shining
for i in range(1,len(A)+1):
    number = i
    matchlist = list(range(1,number+1)) # list of 1 to N ascending numbers
    sublist = A[:i] #sublist of the first N elements
    #print(matchlist)
    #print(sublist)
    # checks difference in lists; if empty, then bulbs will shine
    newlist = set(sublist) - set(matchlist)
    if not newlist:
        shine = shine+1
print(shine)
