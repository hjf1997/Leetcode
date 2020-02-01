from typing import List
# 60ms 89.49%
#13.1MB 59.04%
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        left = 0
        max = 0
        current_length = 0
        element_map = {}
        for i in range(len(s)):
            element = s[i]
            if element not in element_map.keys() or (element in element_map.keys() and element_map[element] < left):
                element_map[element] = i
                current_length += 1
                if current_length > max:
                    max = current_length
            else:
                current_length -= element_map[element] - left
                left = element_map[element] + 1
                element_map[element] = i
        return max

l= 'abcabcbb'
a = Solution()
b = print(a.lengthOfLongestSubstring(l))