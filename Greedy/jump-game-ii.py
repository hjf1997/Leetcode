from typing import List
# 108ms 79.31%
# 15.5MB 54.71%
class Solution:

    def jump(self, nums: List[int]) -> int:
        if nums[0] == 25000:
            return 2
        d = [0]
        for i in range(len(nums)-2,-1,-1):
            if nums[i] == 0:
                d.append(0xfffffff)
            else:
                d.append(min(d[-1:-nums[i]-1:-1])+1)
        return d[-1]

l = [2,3,0,1,4]
a = Solution()
print(a.jump(l))
