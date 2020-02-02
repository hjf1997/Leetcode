# 88ms 8.17%
# 13.3MB 56.52%
class Solution:

    def intToRoman(self, num: int) -> str:

        mapping = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C',
                   500: 'D', 1000: 'M'}
        ans = ''
        for i in range(0,4):
            co = num % (10 ** (i+1))
            num -= co
            ju = int(co / (10 ** i))
            if ju == 4:
                ans = mapping[10**i] + mapping[5*10**i] + ans
            elif 9 > ju >= 5:
                for j in range(ju-5):
                    ans = mapping[10**i] + ans
                ans = mapping[5*10**i] + ans
            elif ju == 9:
                ans = mapping[10**i] + mapping[10**(i+1)] + ans
            else:
                for j in range(1, ju+1):
                    ans = mapping[10**i] + ans
        return ans

a = Solution()
print(a.intToRoman(1994))
