from typing import List

# 112 ms 61.32%
# 15.3MB 66.09%
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:

        maxprice = float('inf')
        dp = [0 if i == src else maxprice for i in range(n)]
        for i in range(K+1):
            tmp = dp[:]
            for v, u, w in flights:
                dp[u] = min(dp[u], tmp[v]+w)
        return dp[dst] if dp[dst] != float('inf') else -1


if __name__ == '__main__':

    n = 3
    edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0
    dst = 2
    k = 0

    a=Solution()
    print(a.findCheapestPrice(n, edges, src, dst, k))