# 72ms 40.04%
# 15MB 40.34%
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        cache = ["" for _ in range(numRows)]
        flat = 'up'
        cache_index = 0
        s_index = 0
        while s_index < len(s):
            cache[cache_index] += s[s_index]
            s_index += 1

            if cache_index == 0:
                flat = 'down'
            elif cache_index == len(cache) - 1:
                flat = 'up'

            if flat == 'down':
                cache_index += 1
            else:
                cache_index -= 1
        return ''.join(cache)

if __name__ == '__main__':
    s = Solution()
    nums = 'AB'
    target = 1
    print(s.convert(nums, target))