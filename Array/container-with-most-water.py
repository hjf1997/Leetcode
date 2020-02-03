from typing import List
# 140ms 84.30%
# 14.4 MB 55.65%
class Solution:


    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0
        while left < right:
            min_height = min(height[left], height[right])
            area = (right - left) * min_height
            if min_height == height[left]:
                left += 1
            else:
                right -=1
            if area > max_area:
                max_area = area
        return max_area
    
li = [1,8,6,2,5,4,8,3,7]
a = Solution()
print(a.maxArea(li))