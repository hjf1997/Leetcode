# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

import copy

class Solution:

    def __init__(self):
        self.treelist = []
        self.treelist.append([None])  # tree with 0 node is None type
        self.traversal_node = []

    def generateTrees(self, n: int):
        if n == 0:
            return []
        for i in range(1, n + 1):
            sublist = []
            for j in range(i):
                for k in range(len(self.treelist[j])):
                    for m in range(len(self.treelist[i - 1 - j])):
                        newnode = TreeNode(None)
                        newnode.left = copy.deepcopy(self.treelist[j][k])
                        newnode.right = copy.deepcopy(self.treelist[i - 1 - j][m])
                        sublist.append(newnode)
            self.treelist.append(sublist)
        ans = self.treelist[-1]
        for i in range(len(ans)):
            self.inorderTraversal(ans[i])

        return ans

    def inorderTraversal(self, root: TreeNode):
        count = 1
        self.judgeLeftChild(root)
        while len(self.traversal_node) != 0:
            node = self.traversal_node.pop()
            node.val = count
            count += 1
            if node.right is not None:
                self.judgeLeftChild(node.right)

    def judgeLeftChild(self, root: TreeNode):
        self.traversal_node.append(root)
        while self.traversal_node[-1].left is not None:
            node = self.traversal_node[-1]
            self.traversal_node.append(node.left)

n = Solution()
a = n.generateTrees(3)