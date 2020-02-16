from typing import List
# 48ms 58.22%
# 13.2Mb 38.25
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:

        stack = []
        count = 0
        nums = len(num) - k
        for i in range(len(num)):

            current = num[i]
            if stack and len(stack) == nums and num[i] >= stack[-1]:
                count += 1
            else:
                while stack and current < stack[-1] and count < k:
                    stack.pop()
                    count += 1
                stack.append(current)

        while count < k:
            stack.pop()
            count += 1

        while len(stack) >= 2 and stack[0] == '0':
            stack.pop(0)
        if len(stack) == 0:
            stack.append('0')
        return ''.join(stack)

a = Solution()
l = '10'
print(a.removeKdigits(l, 2))