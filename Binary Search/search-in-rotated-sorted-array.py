# 32ms 98.25%
# 13.2MB 55.05%
class Solution:

    def search(self, nums, target) -> int:
        if len(nums) == 0:
            return -1
        index = self.findIndex(nums, 0, len(nums) - 1)
        if index is -1:
            return self.searchInSubnums(nums, target, 0 , len(nums)-1, 0)
        if target <= nums[-1]:
            return self.searchInSubnums(nums[index:], target, 0 , len(nums[index:])-1, len(nums[:index]))
        else:
            return self.searchInSubnums(nums[:index], target, 0 , len(nums[:index])-1, 0)

    def findIndex(self, nums, left, right):

        if left + 1 >= right:
            if nums[left] > nums[right]:
                return right
            else:
                return -1

        k = int((left + right) / 2)
        if nums[k] > nums[right]:
            return self.findIndex(nums, k, right)
        elif nums[k] < nums[left]:
            return self.findIndex(nums, left, k)
        return -1

    def searchInSubnums(self, nums, target, left, right, re_len):

        k = int((left+right)/2)
        if nums[k] == target:
            return k + re_len
        if left >= right and nums[k] != target:
            return -1
        if nums[k] < target:
            return self.searchInSubnums(nums, target, k+1, right, re_len)
        elif nums[k] > target:
            return self.searchInSubnums(nums, target, left, k-1, re_len)

nums = [1,3,5]
a = Solution()
print(a.search(nums,1))
