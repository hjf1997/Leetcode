from typing import  List
# 72ms 95.77%
# 16.4MB 40.41%
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        if intervals == []:
            return 0
        start = min(intervals, key=lambda x: x[0])[0]
        delta = 1 - start
        if delta != 0:
            for i in range(len(intervals)):
                intervals[i][0] += delta
                intervals[i][1] += delta
        length = max(intervals, key=lambda x: x[1])[1]
        cash = [[] for i in range(length)]
        d = [0 for i in range(length)]
        for gr in intervals:
            cash[gr[1]-1].append(gr[0]-1)
        d[0] = 1
        for i in range(1, length):
            if cash[i] == []:
                temp = d[i-1]
            else:
                temp = 0
            for j in cash[i]:
                if d[j] + 1 > temp:
                    temp = d[j] + 1
            d[i] = temp
        print(min(d))
        return len(intervals) - max(d) + 1

a = Solution()

print(a.eraseOverlapIntervals(l))