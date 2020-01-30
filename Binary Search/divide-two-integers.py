# 36ms 78.42%
# 13.2MB 56.69%
class Solution:

    def __init__(self):
        self.ans = 0

    def divide(self, dividend: int, divisor: int) -> int:
        if dividend > 0 and divisor < 0:
            ans = -self.binaryDivide(dividend, -divisor, 32, 0)
        elif dividend < 0 and divisor > 0:
            ans = -self.binaryDivide(-dividend, divisor, 32, 0)
        elif dividend < 0 and divisor < 0:
            ans = self.binaryDivide(-dividend, -divisor, 32, 0)
        else:
            ans = self.binaryDivide(dividend, divisor, 32, 0)
        if ans < -1 << 31 or ans > (1<<31) - 1:
            return (1 << 31) - 1
        else:
            return ans
    
    def binaryDivide(self, dividend, divisor, left: int, right: int):

        if divisor > dividend:
            return self.ans

        upper = divisor << (left + right >> 1)
        if upper <= dividend:
            if left - 1 == right:
                self.ans += 1 << (left + right >> 1)
                return self.binaryDivide(dividend-upper, divisor, left, 0)
            else:
                return  self.binaryDivide(dividend, divisor, left, left + right >> 1)
        else:
            return self.binaryDivide(dividend, divisor, left + right >> 1, right)

a = Solution()
print(a.divide(10000, 3))
