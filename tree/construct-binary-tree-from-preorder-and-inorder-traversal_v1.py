from TreeNode import TreeNode
# 64ms 94.50%
# 17.6MB 90.02%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __init__(self):
        self.p_infinity = 0xfffffffffffffff
        self.mark_dic = {}
        self.invert_mark_dic = {}
        self.count = 0

    def buildTree(self, preorder, inorder) -> TreeNode:
        for i in range(len(preorder)):
            self.mark_dic[inorder[i]] = i
            self.invert_mark_dic[i] = inorder[i]
        self.preorder = preorder
        self.inorder = inorder
        self.c = 0
        return self.inorderBuild(None, -self.p_infinity, self.p_infinity)

    def inorderBuild(self, root, min, max, flat='lefe'):

        if self.count == len(self.preorder):
            return

        index = self.mark_dic[self.preorder[self.count]]
        num = self.invert_mark_dic[index]

        if root is None:
            root = TreeNode(num)
            self.count += 1
            self.inorderBuild(root, min, index, 'left')
            self.inorderBuild(root, index, max, 'right')
            return root

        if max > index > min:
            new_node = TreeNode(num)
            if flat == 'left':
                root.left = new_node
            elif flat == 'right':
                root.right = new_node
            self.count += 1
            self.inorderBuild(new_node, min, index, 'left')
            self.inorderBuild(new_node, index, max, 'right')



s = Solution()
a = s.buildTree([2,1,0,4,3,5,6], [0,1,2,3,4,5,6])





