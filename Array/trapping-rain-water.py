from typing import  List

class Solution:
    def trap(self, height: List[int]) -> int:
        index_max = 0
        high = 0
        for i in range(len(height)):
            if height[i] > high:
                index_max = i
                high = height[i]
        return self.getMaxWater(height[:index_max], 'left') + self.getMaxWater(height[index_max+1:], 'right')

    def getMaxWater(self, sub_height, flat):
        if len(sub_height) <= 1:
            return 0
        high = 0
        index_high = 0
        for i in range(len(sub_height)):
            if sub_height[i] >= high:
                high = sub_height[i]
                index_high = i
        if flat == 'right':
            area = index_high * high
            for i in range(index_high):
                area -= sub_height[i]
            area += self.getMaxWater(sub_height[index_high+1:], 'right')
        elif flat == 'left':
            area = (len(sub_height) - 1 - index_high) * high
            for i in range(index_high+1, len(sub_height)):
                area -= sub_height[i]
            area += self.getMaxWater(sub_height[:index_high], 'left')
        return area

a = Solution()
l = [0,3,0,8,4,3,0,13,0,0,6,0,9,0,2,6,0,4]
print(a.trap(l))
