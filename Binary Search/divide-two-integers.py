


class Solution:

    def __init__(self):
        self.ans = 0

    def divide(self, dividend: int, divisor: int) -> int:
        if dividend > 0 and divisor < 0:
            divisor = -divisor
        elif dividend < 0 and divisor > 0:
            dividend = -dividend

        return self.binaryDivide(dividend, divisor, 32, 0)

    def judgeUpper(self, dividend, divisor, multiple: int):
        if divisor << multiple >= dividend:
            return False
        return True
    
    def binaryDivide(self, dividend, divisor, left: int, right: int):
        if divisor > dividend:
            if self.ans > (1<< 31) - 1:
                return (1<< 31) - 1
            else:
                return self.ans
        upper = divisor << (left + right>> 1)
        if upper <= dividend:
            if self.judgeUpper(dividend, divisor, left + (left + right + 1>> 1) >> 1) is False:
                self.ans += 1 << (left + right>> 1)
                return self.binaryDivide(dividend-upper, divisor, (left + right>> 1), 0)
            else:
                return self.binaryDivide(dividend, divisor, left, (left + right>> 1))
        else:
            return self.binaryDivide(dividend, divisor, left + right>> 1, 0)

a = Solution()
print(a.divide(1000, 1))
