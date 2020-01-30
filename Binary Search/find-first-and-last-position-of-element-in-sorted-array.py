# 120ms 23.50%
# 14.3MB 54.02%
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        if length == 0:
            return [-1, -1]
        index1 = self.findMinimum(nums, target, 0, length-1)
        index2 = self.findMaximum(nums[index1:], target, 0, len(nums[index1:])-1)
        if index2 != -1:
            index2 += index1
        return [index1, index2]

    def findMinimum(self, nums, target, left, right):
        if left == right:
            if nums[right] == target:
                return right
            else:
                return -1
        k = int((left+right)/2)
        if nums[k] >= target:
            return self.findMinimum(nums, target, left, k)
        else:
            return self.findMinimum(nums, target, k+1, right)

    def findMaximum(self, nums, target, left, right):
        if left == right:
            if nums[left] == target:
                return left
            else:
                return -1
        k = int((left+right + 1)/2)
        if nums[k] > target:
            return self.findMaximum(nums, target, left, k-1)
        else:
            return self.findMaximum(nums, target, k, right)

l = [-5,-5,0,0,1,1,1,1,1,1,2,2,5,5,7,7]
l = [1,1,1,1,1,1,1,1,1]
a = Solution()
b = a.searchRange(l, 1)
print(b)