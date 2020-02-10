from typing import List
# 152ms 13.77%
# 15.4MB 46.61%
class Solution:

    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return True
        index = len(nums) -1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] + i >= index:
                index = i
        if index == 0:
            return True
        return False

l = [3,2,1,0,4]
a = Solution()
print(a.canJump(l))
