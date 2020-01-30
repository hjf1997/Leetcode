# Catalan 1/(n+1) * C(n, 2n)
# C(n, 2n) = 2n (2n-1) ... (n+1) / n (n-1) (n-2) ... 1
class Solution:
    def numTrees(self, n: int) -> int:
        count = 1
        for i in range(1, n+1):
            count = (n + i) * count / i
        return int(count / (n+1))