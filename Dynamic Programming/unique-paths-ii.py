from typing import List
# 120ms 5.48%
# 28.7MB 5.11%
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        d = [[0 for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if i == j == 0  and obstacleGrid[i][j] == 0:
                    d[i][j] = 1
                elif obstacleGrid[i][j] == 1:
                    d[i][j] = 0
                else:
                    d[i][j] = d[i-1][j] + d[i][j-1]
        return d[-1][-1]

a = Solution()
l = [
  [0]
]
print(a.uniquePathsWithObstacles(l))