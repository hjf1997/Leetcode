# 44ms 25.54%
#13.1Mb 47.29%

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        d = [[0 for j in range(n)] for i in range(m)]
        d[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                d[i][j] += d[i-1][j] + d[i][j-1]
        return d[-1][-1]

a = Solution()
print(a.uniquePaths(2,1))