# 108ms 6.01%
#28.8MB 5.22%

class Solution:
    def numDecodings(self, s: str) -> int:
        d = []
        if int(s[0]) > 0:
            d.append(1)
        else:
            d.append(0)

        if len(s) >= 2:
            d.append(0)
            if int(s[1]) > 0:
                d[-1] += d[0]
            if 10 <= int(s[:2]) <= 26:
                d[-1] += 1

        for i in range(2, len(s)):
            add = 0
            if 10 <= int(s[i-1:i+1]) <= 26:
                add += d[i-2]
            if int(s[i]) > 0:
                add += d[i-1]
            d.append(add)
        return d[-1]

a = Solution()
l = '130'
print(a.numDecodings(l))

