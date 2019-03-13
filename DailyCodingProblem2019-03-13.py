# SOLVED... I think?

# There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
# Given N, write a function that returns the number of unique ways you can climb the staircase.
# The order of the steps matters.

# For example, if N is 4, then there are 5 unique ways:

#   1, 1, 1, 1
#   2, 1, 1
#   1, 2, 1
#   1, 1, 2
#   2, 2

# What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number
# from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5
# steps at a time.

A = [1,2] # solution would be 5
B = [1,3,5]
N = 4

class Node:
    def __init__(self, val, runningsum):
        self.val = val
        self.runningsum = runningsum
        self.children = []

    def add_child(self, obj):
        self.children.append(obj)

    def __str__(self, level=0):
        ret = "\t"*level+repr(self.val)+"\n"
        for child in self.children:
            ret += child.__str__(level+1)
        return ret

    def is_leaf(self):
        if not self.children:
            return True

    def count_leaves(self):
        if self.is_leaf():
            return 1
        count = 0
        for i in self.children:
            if i is not None:
                count += i.count_leaves()
        return count

    def add_steps(self, maxsteps, steplist):
        for i in steplist:
            if self.runningsum + i <= maxsteps:
                new_node = Node(i,self.runningsum+i)
                self.add_child(new_node)
                new_node.add_steps(maxsteps, steplist)


root = Node(4,0)
root.add_steps(N, A)
print(root.count_leaves())
