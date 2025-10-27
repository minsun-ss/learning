# SOLVED

# A unival tree (which stands for "universal value") is a tree where all nodes under it have the same
# value.

# Given the root to a binary tree, count the number of unival subtrees.

# For example, the following tree has 5 unival subtrees:

#   0
#  / \
# 1   0
#    / \
#   1   0
#  / \
# 1   1

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    # leaves by default are unival trees
    def is_leaf(self):
        return self.left is None and self.right is None

    def is_unival(self):
        if self.is_leaf():
            return True
        flag = True
        if self.left is not None:
            if self.val != self.left.val:
                return False
            else:
                self.left.is_unival()
        if self.right is not None:
            if self.val != self.right.val:
                return False
            else:
                self.right.is_unival()
        return flag

    def count_unival(self):
        if self.is_unival():
            return 1
        count = 0
        if self.left is not None:
            count += self.left.count_unival()
        if self.right is not None:
            count += self.right.count_unival()
        return count


def serialize(root):
    if root is None:
        return '#'
    return '{} {} {}'.format(root.val, serialize(root.left), serialize(root.right))

root = Node(0)
root.left = Node(1)
right = Node(0)
right.right = Node(0)
rightleft = Node(1)
rightleft.left = Node(1)
rightleft.right = Node(1)
right.left = rightleft
root.right = right

print(serialize(root))
print(root.count_unival())
