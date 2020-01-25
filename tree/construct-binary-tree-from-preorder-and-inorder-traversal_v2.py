from TreeNode import TreeNode
#64ms 94.50%
#17.5MB 90.09%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:


    def buildTree(self, preorder, inorder) -> TreeNode:

        self.preorder = preorder
        self.inorder = inorder
        self.cursor = 0
        self.inorder_index = {}
        for i in range(len(preorder)):
            self.inorder_index[inorder[i]] = i
        return self.buildSubTree(None, 0, len(self.preorder)-1)

    def buildSubTree(self, root, left=0, right=0xfffff, flat='left'):

        if self.cursor == len(self.preorder):
            return

        current = self.preorder[self.cursor]
        new_node = TreeNode(current)
        if flat == 'left' and root is not None:
            root.left = new_node
        elif flat == 'right' and root is not None:
            root.right = new_node
        self.cursor += 1
        if self.inorder[left] != current:
            self.buildSubTree(new_node, left, self.inorder_index[current]-1, 'left')
        if self.inorder[right] != current:
            self.buildSubTree(new_node, self.inorder_index[current]+1, right, 'right')

        if root is None:
            return new_node

s = Solution()
a = s.buildTree([2,1,0,4,3,5,6], [0,1,2,3,4,5,6])




