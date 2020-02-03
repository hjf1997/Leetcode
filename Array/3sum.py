from typing import List
import copy
class Solution:


    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        nums.sort()
        ans = []
        map_hash = {}
        for i in range(0, len(nums)-1):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = 0
            right = len(nums) - 1
            while left < right:
                if left == i:
                    left += 1
                    continue
                elif right == i:
                    right -= 1
                    continue
                if nums[left] + nums[right] + nums[i] < 0:
                    left += 1
                elif nums[left] + nums[right] + nums[i] > 0:
                    right -= 1
                else:
                    row = sorted([nums[left], nums[i], nums[right]])
                    map_hash[row[0], row[1], row[2]] = 1
                    left += 1
                    right -= 1
        for i in map_hash.keys():
            ans.append(i)
        return ans

l = [-1, 0, 1, 2, -1, -4]
a = Solution()
print(a.threeSum(l))