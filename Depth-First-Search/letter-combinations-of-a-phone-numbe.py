from typing import List
# 32ms 93.50%
# 14.9MB 44.60%

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.digits = digits
        self.digits_len = len(self.digits)
        self.maps = {
            2: 'abc',
            3: 'def',
            4: 'ghi',
            5: 'jkl',
            6: 'mno',
            7: 'pqrs',
            8: 'tuv',
            9: 'wxyz'
        }
        self.ans = []
        if self.digits_len > 0:
            self.DFS(0, '')
        return self.ans

    def DFS(self, index, string):
        # 递归
        for i in range(len(self.maps[int(self.digits[index])])):
            if index == self.digits_len - 1:
                # 返回
                self.ans.append(string + self.maps[int(self.digits[index])][i])
            else:
                self.DFS(index + 1, string + self.maps[int(self.digits[index])][i])


if __name__ == '__main__':
    s = Solution()
    dig = '47'
    print(s.letterCombinations(dig))