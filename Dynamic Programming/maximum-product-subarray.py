from  typing import  List
# 124ms 6.68%
# 29.3MB 5.04%
class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        maximum = 1
        minimum = 1
        ans = 0
        for i in range(len(nums)):
            temp1 = maximum * nums[i]
            temp2 = minimum * nums[i]

            maximum = max(nums[i], max(temp1, temp2))
            minimum = min(nums[i], min(temp1, temp2))

            ans = max(ans, maximum)
        return ans
