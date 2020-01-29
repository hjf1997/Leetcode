# required O(log(m+n))
# 112ms


class Solution:

    def findMedianSortedArrays(self, nums1, nums2) -> float:

        l_s1 = len(nums1)
        l_s2 = len(nums2)
        nums1_k = int((l_s1 + l_s2 + 1) / 2)
        nums2_k = int((l_s1 + l_s2 + 2) / 2)

        return float((self.findKthNumber(nums1, nums2, 0, 0, nums1_k) \
               + self.findKthNumber(nums1, nums2, 0, 0, nums2_k)) / 2)

    def findKthNumber(self, nums1, nums2, nums1_left, nums2_left, k):

        l_s1 = len(nums1) - nums1_left
        l_s2 = len(nums2) - nums2_left

        if l_s1 > l_s2:
            return self.findKthNumber(nums2, nums1, nums2_left, nums1_left, k)
        if l_s1 == 0:
            return nums2[nums2_left + k - 1]

        if k == 1:
            return min(nums1[nums1_left], nums2[nums2_left])

        i = nums1_left + min(l_s1, int(k/2)) - 1
        j = nums2_left + min(l_s2, int(k/2)) - 1

        if nums1[i] > nums2[j]:
            return self.findKthNumber(nums1, nums2, nums1_left, j+1, k - (j - nums2_left + 1))
        else:
            return self.findKthNumber(nums1, nums2, i+1, nums2_left, k - (i - nums1_left + 1))

a = Solution()
b = a.findMedianSortedArrays([1],[2,3,4,5,6])
print(b)


