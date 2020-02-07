# 52ms 89.38%
# 13.8MB 52.47%
from typing import  List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        ans = -1
        for i in range(len(nums)):
            while 0 < nums[i] <= len(nums) and nums[i] != i+1 and nums[i] != nums[nums[i]-1]:
                tn = nums[i]
                nums[i] = nums[tn-1]
                nums[tn-1] = tn
        for i in range(len(nums)):
            if nums[i] != i+1:
                ans = i+1
                break
        if ans == -1:
            ans = len(nums) + 1
        return ans

l = [1,1]
a = Solution()
print(a.firstMissingPositive(l))