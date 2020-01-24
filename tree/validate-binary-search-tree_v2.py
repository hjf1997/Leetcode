from TreeNode import TreeNode

#/原node更新右
#\原node更新左

class Solution:

    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        max = 0xffffffff
        min = -0xffffffff
        return self.nodeIsValid(root, max, min)

    def nodeIsValid(self, root: TreeNode, max, min):

        if root.val >= max or root.val <= min:
            return False

        if root.left is not None and self.nodeIsValid(root.left, max=root.val, min=min) is False:
            return False
        if root.right is not None and self.nodeIsValid(root.right, max=max, min=root.val) is False:
            return False

        return True


root = TreeNode(5)
root_left = TreeNode(1)
root.left = root_left
root_right = TreeNode(4)
root.right = root_right

n = Solution()
a = n.isValidBST(root)
print(a)
