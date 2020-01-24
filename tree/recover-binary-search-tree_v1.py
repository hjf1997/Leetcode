from TreeNode import TreeNode
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __init__(self):
        self.traversal_node = []
        self.found_first = False
        self.former = TreeNode(-0xffffffffff)
        self.current = 0
        self.adjacent = None
        self.error = []

    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.findErrorNode(root)
        temp = self.error[0].val
        self.error[0].val = self.error[1].val
        self.error[1].val = temp

    def findErrorNode(self, root: TreeNode):
        if root is None:
            return self.traversal_list
        self.judgeLeftChild(root)
        while len(self.traversal_node) != 0:
            node = self.traversal_node.pop()
            if node.val < self.former.val:
                if self.found_first is False:
                    self.error.append(self.former)
                    self.adjacent = node
                    self.found_first = True
                else:
                    self.error.append(node)
            self.former = node
            if node.right is not None:
                self.judgeLeftChild(node.right)
        if len(self.error) == 1:
            self.error.append(self.adjacent)
        return self.error

    def judgeLeftChild(self, root: TreeNode):
        self.traversal_node.append(root)
        while self.traversal_node[-1].left is not None:
            node = self.traversal_node[-1]
            self.traversal_node.append(node.left)

root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.left = TreeNode(2)

n = Solution()
n.recoverTree(root)

