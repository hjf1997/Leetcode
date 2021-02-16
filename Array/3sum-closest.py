from typing import List

# 260 ms 16.76%
# 14.9 32.63%
# 还可以添加剪枝，当sublist左边加起来还比target大，或者右边加起来还比target小 都可以直接break了
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = 0xfffffff
        nums.sort()
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            temp = target - nums[i]
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if abs(target - ans) > abs(target - nums[left] - nums[right] - nums[i]):
                    ans = nums[left] + nums[right] + nums[i]
                if nums[left] + nums[right] > temp:
                    right -= 1
                elif nums[left] + nums[right] < temp:
                    left += 1
                else:
                    break
        return ans

if __name__ == '__main__':
    s = Solution()
    nums = [2,2,2,4,7]
    target = 11
    print(s.threeSumClosest(nums, target))