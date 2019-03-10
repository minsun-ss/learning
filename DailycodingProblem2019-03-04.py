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

# take a node and flatten it into a string
def tostring(anode, level = 0, filename = 'temp.txt'):
    data = open(filename,"a")
    data.write(anode.val+"\r\n")
    data.write(str(level)+"\r\n")
    if anode.left:
        level = level+1
        tostring(anode.left, level)
    if anode.right:
        tostring(anode.right, level)
    return filename

def get_children(anode):
    children = []
    if anode.left:
        children.append(str(anode.left.val))
    else:
        children.append("None")
    if anode.right:
        children.append(str(anode.right.val))
    else:
        children.append("None")
    return children

def have_children(anode):
    if anode.left:
        return True
    elif anode.right:
        return True
    else:
        return False

def have_grandchildren(anode):
    if have_children(anode.left):
        return True
    elif have_children(anode.right):
        return True
    else:
        return False

def deserialize(anode):
    if have_grandchildren(anode):
        deserialize(anode.left)

node = Node('root', Node('left', Node('left.left')), Node('right'))

print(get_children(node))
print(have_children(node))
print(have_grandchildren(node))