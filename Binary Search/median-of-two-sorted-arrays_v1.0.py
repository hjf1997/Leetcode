#　required O(log(m+n))
# 104ms 82.84%
# 13.2MB 58.39%
class Solution:


    def findMedianSortedArrays(self, nums1, nums2) -> float:

        length = len(nums1) + len(nums2)
        # The index-th biggest number is what we need, if length is even we also need index+1-th
        index = int((length + 1) / 2)
        nums1_left = -1
        nums2_left = -1
        ans = 0.
        flat = 2
        if length % 2 != 0:
            flat = 1

        while index > 0:
            if index == 1:
                for i in range(flat):
                    if nums1_left >= len(nums1) - 1:
                        nums2_left += 1
                        ans += nums2[nums2_left]
                    elif nums2_left >= len(nums2) - 1:
                        nums1_left += 1
                        ans += nums1[nums1_left]
                    else:
                        if nums1[nums1_left+1] < nums2[nums2_left+1]:
                            nums1_left += 1
                            ans += nums1[nums1_left]
                        else:
                            nums2_left += 1
                            ans += nums2[nums2_left]
                ans /= flat
                break
            k = int(index / 2)
            if nums1_left >= len(nums1) - 1:
                for i in range(flat):
                    nums2_left += 1
                    ans += nums2[nums2_left + index - 1]
                ans /= flat
                break
            if nums2_left >= len(nums2) - 1:
                for i in range(flat):
                    nums1_left += 1
                    ans += nums1[nums1_left + index - 1]
                ans /= flat
                break
            if nums1_left + k >= len(nums1) - 1:
                nums1_current = nums1[-1]
                minus1 = len(nums1) - nums1_left -1
            else:
                nums1_current = nums1[nums1_left + k]
                minus1 = k
            if nums2_left + k >= len(nums2) - 1:
                nums2_current = nums2[-1]
                minus2 = len(nums2) - nums2_left -1
            else:
                nums2_current = nums2[nums2_left + k]
                minus2 = k

            if nums1_current >= nums2_current:
                nums2_left += k
                index -= minus2
            else:
                nums1_left += k
                index -= minus1

        return float(ans)

a = Solution()
b = a.findMedianSortedArrays([1,2,3,4],[])
print(b)