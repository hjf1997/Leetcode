#　required O(log(m+n))
# 112ms 64.28%
# 13.2MB 58.39%
class Solution:


    def findMedianSortedArrays(self, nums1, nums2) -> float:
    
        l_s1 = len(nums1)
        l_s2 = len(nums2)
        if l_s1 > l_s2:
            return self.findMedianSortedArrays(nums2, nums1)
        # The index-th biggest number is what we need, if length is even we also need index+1-th
        index = int((l_s1 + l_s2 + 1) / 2)
        nums1_left = 0
        nums2_left = 0
        ans = 0.
        flat = 2
        if (l_s1 + l_s2) % 2 != 0:
            flat = 1

        while index > 0:

            if nums1_left > l_s1 - 1:
                nums2_left += index - 1
                for i in range(flat):
                    ans += nums2[nums2_left]
                    nums2_left += 1
                return float(ans/flat)

            if index == 1:
                for i in range(flat):
                    if nums2_left > len(nums2) - 1:
                        ans += nums1[nums1_left]
                        nums1_left += 1
                    elif nums1_left > len(nums1) - 1:
                        ans += nums2[nums2_left]
                        nums2_left += 1
                    else:
                        if nums1[nums1_left] <= nums2[nums2_left]:
                            ans += nums1[nums1_left]
                            nums1_left += 1
                        else:
                            ans += nums2[nums2_left]
                            nums2_left += 1
                return float(ans/flat)

            k = int(index / 2) - 1
            x = min(l_s1-1, nums1_left+k)
            nums1_current = nums1[x]
            y = min(l_s2-1, nums2_left+k)
            nums2_current = nums2[y]

            if nums1_current > nums2_current:
                index -= y - nums2_left + 1
                nums2_left += k + 1
            else:
                index -= x - nums1_left + 1
                nums1_left += k + 1

        return float(ans)

a = Solution()
b = a.findMedianSortedArrays([4],[1,2,3,5])
print(b)