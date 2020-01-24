# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:

    def __init__(self):
        self.traversal_node = []
        self.traversal_list = []

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return self.traversal_list
        self.judgeLeftChild(root)
        while len(self.traversal_node) != 0:
            node = self.traversal_node.pop()
            self.traversal_list.append(node.val)
            if node.right is not None:
                self.judgeLeftChild(node.right)
        return self.traversal_list

    def judgeLeftChild(self, root: TreeNode):
        self.traversal_node.append(root)
        while self.traversal_node[-1].left is not None:
            node = self.traversal_node[-1]
            self.traversal_node.append(node.left)

