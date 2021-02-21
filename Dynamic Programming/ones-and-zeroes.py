from typing import List
# 2832 ms 87.77%
# 14.9 MB 76.70%

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        d = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for sub_s in strs:
            m_num = sub_s.count('0')
            n_num = sub_s.count('1')
            for m_ in range(m, m_num-1, -1):
                for n_ in range(n, n_num-1, -1):
                    d[m_][n_] = max(d[m_][n_], d[m_-m_num][n_-n_num]+1)
        return d[-1][-1]

if __name__ == '__main__':

    a = Solution()
    strs = ["100"]
    m = 1
    n = 1
    print(a.findMaxForm(strs, m, n))
