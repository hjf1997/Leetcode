from typing import  List
# 236ms 5.90%
# 30.4MB 5.01%
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j == 0:
                    continue
                elif i == 0 and j != 0:
                    grid[i][j] += grid[i][j-1]
                elif i != 0 and j == 0:
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]

a = Solution()
l = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
print(a.minPathSum(l))
