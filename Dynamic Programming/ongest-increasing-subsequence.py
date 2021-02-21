from typing import List
# 3484ms 53.73%
# 15.2 MB 5.28%

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        d = [1 for _ in range(len(nums))]
        for i in range(1, len(nums)):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    d[i] = max(d[i], d[j]+1)
        return max(d)

if __name__ == '__main__':

    a = Solution()
    nums = [4,10,4,3,8,9]
    print(a.lengthOfLIS(nums))