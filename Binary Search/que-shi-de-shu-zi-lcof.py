from typing import List
"""
36ms 96.98%
14.5MB 9.97%
"""

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        left_cur = 0
        right_cur = len(nums) - 1
        while left_cur < right_cur:
            mid_cur = left_cur + int((right_cur - left_cur) / 2)
            if mid_cur < nums[mid_cur]:
                right_cur = mid_cur - 1
            else:
                left_cur = mid_cur + 1

        if nums[left_cur] > left_cur:
            return nums[left_cur] - 1
        else:
            return left_cur + 1

if __name__ == '__main__':
    a = Solution()
    print(a.missingNumber([0,1,3,4,5,6,7,8]))