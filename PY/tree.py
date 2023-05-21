class Node:
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None


def createTree(nodes):
    idx = [-1]

    def helper():
        idx[0] += 1

        if nodes[idx[0]] == -1:
            return None

        newNode = Node(nodes[idx[0]])
        newNode.left = helper()
        newNode.right = helper()

        return newNode

    return helper()


def inOrder(root):
    if not root:
        return

    inOrder(root.left)
    print(root.val, end=" ")
    inOrder(root.right)


def inOrderIter(root):
    stack = []
    curr = root

    while stack or curr:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        print(curr.val, end=" ")

        curr = curr.right
    print()


def preOrderIter(root):
    stack = [root]
    curr = None

    while stack:
        curr = stack.pop()
        print(curr.val, end=" ")

        if(curr.right):
            stack.append(curr.right)
        if(curr.left):
            stack.append(curr.left)
    print()


def postOrderIter(root):
    s1 = [root]
    s2 = []

    while s1:
        node = s1.pop()
        s2.append(node)

        if(node.left):
            s1.append(node.left)
        if node.right:
            s1.append(node.right)
    while s2:
        curr = s2.pop()
        print(curr.val, end=" ")

    print()


nodes = [1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1]
root = createTree(nodes)
inOrder(root)
print()
inOrderIter(root)
preOrderIter(root)
postOrderIter(root)
