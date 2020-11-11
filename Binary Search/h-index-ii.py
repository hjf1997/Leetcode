from typing import List
# 56ms 26.36%
# 17.6MB 51.35%

class Solution:
    def hIndex(self, citations: List[int]) -> int:

        while len(citations) > 0 and citations[0] == 0:
            citations.pop(0)

        if len(citations) > 0:
            citations.insert(0,0)

        left_cur = 0
        right_cur = max(0, len(citations) - 1)

        while left_cur < right_cur - 1:
            mid_cur = left_cur + int((right_cur - left_cur) / 2)
            paper_nums = len(citations) - mid_cur
            if citations[mid_cur] < paper_nums:
                left_cur = mid_cur
            else:
                right_cur = mid_cur

        return len(citations) - right_cur

if __name__ == '__main__':
    a = Solution()
    print(a.hIndex([0,1,3,5,6]))