# SOLVED

# Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be
# decoded.

# For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

# You can assume that the messages are decodable. For example, '001' is not allowed.

str = '111111'
# answer should be 3

class Node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print (self.val)
        if self.right:
            self.right.PrintTree()

    def is_leaf(self):
        return self.right is None and self.left is None

    def count_leaves(self):
        if self.is_leaf():
            return 1
        count = 0
        if self.left is not None:
            count += self.left.count_leaves()
        if self.right is not None:
            count += self.right.count_leaves()
        return count

def serialize(root):
    if root is None:
        return '#'
    return '{} {} {}'.format(root.val, serialize(root.left), serialize(root.right))

def insert(val, node):
    newnode = Node(val)
    if val < 10:
        node.left = newnode
    elif val > 9:
        node.right = newnode
    else:
        return None
    return newnode

def buildNode(str, node):
    left = int(str[0])
    right = int(str[0:2])
    leftremainder = str[1:]
    rightremainder = str[2:]
    if left != "":
        newnode = insert(left, node)
        if leftremainder != "":
            buildNode(leftremainder, newnode)
    if right != "" and right <= 26:
        newnode = insert(right, node)
        if rightremainder != "":
            buildNode(rightremainder, newnode)
    return node


root = Node(str)
buildNode(str, root)
print(serialize(root))
print(root.count_leaves())