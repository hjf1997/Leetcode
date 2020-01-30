from TreeNode import TreeNode


class Solution:

    def __init__(self):
        self.traversal_node = []
        self.flat = -0xfffffff

    def isValidBST(self, root: TreeNode) -> bool:

        if root is None:
            return False
        self.judgeLeftChild(root)
        while len(self.traversal_node) != 0:
            node = self.traversal_node.pop()
            if node.val <= self.flat:
                return False
            else:
                self.flat = node.val
            if node.right is not None:
                self.judgeLeftChild(node.right)
        return True

    def judgeLeftChild(self, root: TreeNode):
        self.traversal_node.append(root)
        while self.traversal_node[-1].left is not None:
            node = self.traversal_node[-1]
            self.traversal_node.append(node.left)



