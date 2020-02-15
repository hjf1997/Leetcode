from typing import List
# 52ms 30.46%
# 13.1MB 35.75%
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        minus = [nums[i] - nums[i-1] for i in range(1, len(nums))]
        if minus[0] == 0:
            length = 1
        else:
            length = 2
        cursor = minus[0]
        for i in range(1, len(minus)):
            if (cursor - minus[i]/0xffffff) * minus[i] < 0:
                cursor = minus[i]
                length += 1
        return length

a= Solution()
l = [0,0]
print(a.wiggleMaxLength(l))
