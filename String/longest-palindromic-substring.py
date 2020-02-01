from typing import List
# 1160ms 63.29%
# 13MB 67.44%
class Solution:

    def longestPalindrome(self, s: str) -> str:
        ans = ''
        if s == '':
            return ''
        for i in range(1, len(s)-1):
            len_sub1 = len(s[:i])
            len_sub2 = len(s[i+1:])
            length = min(len_sub1, len_sub2)
            substr = self.findMaxSubstr(s[len_sub1-length:i], s[i+1:i+length+1])
            if 2*len(substr)+1 > len(ans):
                ans = substr[::-1] + s[i] + substr
        for i in range(1, len(s)):
            len_sub1 = len(s[:i])
            len_sub2 = len(s[i:])
            length = min(len_sub1, len_sub2)
            substr = self.findMaxSubstr(s[len_sub1-length:i], s[i:i+length])
            if 2*len(substr) > len(ans):
                ans = substr[::-1] + substr
        if ans == '' or len(ans) == 1:
            return s[0]
        return ans

    def findMaxSubstr(self, sub1, sub2):
        pos_sub = ''
        length = len(sub1)
        for i in range(length-1,-1,-1):
            if sub1[i] == sub2[length-1-i]:
                pos_sub += sub1[i]
            else:
                break
        return pos_sub

a = Solution()
print(a.longestPalindrome('babad'))