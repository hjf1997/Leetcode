from typing import List
import copy

# 520ms 95.99%
# 18MB 7.87%
# 可以使用set类  add函数添加
class Solution:


    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)-2):
            target = -nums[i]
            # 剪枝1
            if i > 0 and nums[i-1] == nums[i]:
                continue

            # 剪枝2
            if nums[i+1] + nums[i+1] > target or nums[-1] + nums[-2] < target:
                continue

            left, right = i + 1, len(nums)-1
            while left < right:
                if nums[left] + nums[right] < target:
                    left += 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    # 去重
                    if len(ans) == 0 or ans[-1] != [-target, nums[left], nums[right]]:
                        ans.append([-target, nums[left], nums[right]])
                    left += 1
                    right -= 1
        return ans

if __name__ == '__main__':

    l = [-2, -1, 0, 0, 2, 2]
    a = Solution()
    print(a.threeSum(l))