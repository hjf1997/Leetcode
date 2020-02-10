from typing import  List
# 36ms 82.66%
# 13.1MB 50.47%
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) == 0:
            return

        for i in range(len(matrix)):
            for j in range(i+1, len(matrix)):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            matrix[i].reverse()

l = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
a = Solution()
a.rotate(l)
print(l)