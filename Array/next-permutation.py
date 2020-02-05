from typing import List
# 48ms 64.33%
# 13MB 53.99%
class Solution:

    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = len(nums) - 2
        if len(nums) == 1:
            return
        while left + 1 <= len(nums) - 1 and left > -1 and nums[left] >= nums[left+1]:
            left -= 1
        if left == -1:
            nums.reverse()
            return
        temp = 0xfffffffff
        index = 0
        ex = 0
        for i in range(left+1, len(nums)):
            if nums[i] > nums[left] and nums[left] - nums[i] < temp:
                index = i
        ex = nums[left]
        nums[left] = nums[index]
        nums[index] = ex
        left = left + 1
        right = len(nums) - 1
        while left < right:
            ex = nums[left]
            nums[left] = nums[right]
            nums[right] = ex
            right -= 1
            left += 1
l = [1]
a = Solution()
a.nextPermutation(l)
print(l)
