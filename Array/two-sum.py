# 60ms 75.80%
# 14.1MB 75.37%
from typing import List
import copy
class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_tem = copy.deepcopy(nums)
        nums.sort()
        left = 0
        right = len(nums) - 1
        ans = []
        while left < right:

            if nums[left] + nums[right] > target:
                right -= 1
            elif nums[left] + nums[right] <target:
                left += 1
            else:
                for i in range(len(nums_tem)):
                    if nums[left] == nums_tem[i] or nums[right] == nums_tem[i]:
                        ans.append(i)
                break
        return ans

le = [3,2,4]
tar = 6
a = Solution()
b = a.twoSum(le, tar)
print(b)