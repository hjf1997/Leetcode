# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __init__(self):
        self.traversal_list = []

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return self.traversal_list
        if root.left is None and root.right is None:
            self.traversal_list.append(root.val)
            return self.traversal_list
        if root.left is not None:
            self.inorderTraversal(root.left)
        self.traversal_list.append(root.val)
        if root.right is not None:
            self.inorderTraversal(root.right)
        return self.traversal_list