# 56ms 50.37%
# 13.1MB 72.31%
class Solution:

    def longestValidParentheses(self, s: str) -> int:

        dp = []
        ans = 0
        for i in range(len(s)):
            if i == 0:
                dp.append(0)
                continue
            if s[i] == '(':
                dp.append(0)
            else:
                if s[i-1] == '(':
                    dp.append(dp[i-2]+2)
                elif i-dp[i-1]-1 >= 0 and s[i-dp[i-1]-1] == '(':
                    dp.append(dp[i-1]+dp[max(i-dp[i-1]-2, 0)]+2)
                else:
                    dp.append(0)
            if dp[-1] > ans:
                ans = dp[-1]
        return ans

st = '()(())'
a = Solution()
print(a.longestValidParentheses(st))