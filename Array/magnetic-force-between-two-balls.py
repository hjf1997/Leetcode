from typing import List
# 思路: 可以二分答案
# 892ms 73.06%
# 24.7 6.39%
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        left = 1
        right = position[-1] - position[0]

        while left < right:
            mid = int((left + right)/2 + 0.5)
            if self.check(position, mid, m):
                left = mid
            else:
                right = mid - 1
        return left

    def check(self, position, mid, m):
        temp = position[0]
        count = 1
        for i in position:
            if i - temp >= mid:
                count += 1
                temp = i
        return count >= m

if __name__ == '__main__':
    s = Solution()
    position = [79,74,57,22]
    m = 4
    print(s.maxDistance(position, m))