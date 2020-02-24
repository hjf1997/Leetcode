from typing import List
# 32ms 80.54%
# 13.3MB 35.40%
class Solution:
    def rob(self, nums: List[int]) -> int:

        if len(nums) == 0:
            return 0
        d1 = [nums[0]] # 要
        d2 = [0] # 不要
        for i in range(1, len(nums)):

            d2.append(max(d1[i-1], d2[i-1]))
            d1.append(max(d2[i-1], 0 if i-2<0 else d1[i-2]) + nums[i])

        return max(d1[-1],d2[-1])


a = Solution()
l = [1]
print(a.rob(l))
