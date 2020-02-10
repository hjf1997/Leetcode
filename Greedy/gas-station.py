from typing import List
# 64ms 60.07%
# 14.3MB 53.35%
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        delta = [gas[i] - cost[i] for i in range(len(gas))]
        if len(delta) == 0:
            return -1
        elif len(delta) == 1:
            if delta[0] >= 0:
                return 0
            else:
                return -1
        left = 0
        right = 0
        total = delta[left]
        while True:
            if total < 0:
                if left == 0:
                    left = len(delta) - 1
                else:
                    left -= 1
                total += delta[left]
            else:
                right = (right + 1) % (len(delta))
                total += delta[right]
            if left == right:
                break
        if total >= 0:
            return left
        else:
            return -1

a = Solution()
gas  = [1,2]
cost = [2,1]
print(a.canCompleteCircuit(gas, cost))
