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
                        newnode = TreeNode(j+1)
                        newnode.left = self.treelist[j][k]
                        newnode.right = copy.deepcopy(self.treelist[i - 1 - j][m])
                        self.addOffsett(newnode.right, j+1)
                        sublist.append(newnode)
            self.treelist.append(sublist)
        return self.treelist[-1]

    def addOffsett(self, root, offset):

        if root is None:
            return
        root.val += offset
        self.addOffsett(root.left, offset)
        self.addOffsett(root.right, offset)


n = Solution()
a = n.generateTrees(3)