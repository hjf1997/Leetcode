from typing import List
# 76ms 53.20%
# 14.4Mb 54.72%
class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(1, len(prices)):
            ans += max(0, prices[i]-prices[i-1])
        return ans
l = [1,2,3,4,5]
a = Solution()
print(a.maxProfit(l))
