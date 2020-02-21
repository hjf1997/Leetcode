from typing import List
# 136ms 7.01%
# 29.5MB 5.07%
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if len(triangle[0]) == 0:
            return 0
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                boundary = len(triangle[i]) -1
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j == boundary:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1])
        return min(triangle[-1])

a = Solution()
l = [
     []
]
print(a.minimumTotal(l))