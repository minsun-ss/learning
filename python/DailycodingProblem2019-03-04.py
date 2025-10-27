# Given the root to a binary tree, implement serialize(root), which serializes the tree into a
# string, and deserialize(s), which deserializes the string back into the tree.

# For example, given the following Node class

# class Node:
 #   def __init__(self, val, left=None, right=None):
 #       self.val = val
 #       self.left = left
 #       self.right = right

# The following test should pass:

# node = Node('root', Node('left', Node('left.left')), Node('right'))
# assert deserialize(serialize(node)).left.left.val == 'left.left'

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def has_children(self):
        return self.left is not None and self.right is not None

def serialize(node):
    if node is None:
        return '#'
    return '{} {} {}'.format(node.val, serialize(node.left), serialize(node.right))

def deserialize(str):

    strlist = str.split()
    for i in strlist:
        if i != '#':
            temp = Node(i)




node = Node('root', Node('left', Node('left.left')), Node('right'))


flat = serialize(node)
print(flat)
deserialize(flat)