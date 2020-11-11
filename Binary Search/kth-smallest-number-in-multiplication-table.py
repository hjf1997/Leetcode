from typing import List
# 1128ms 26.35%
# 13.5MB 5.41%
# 我的解释是这样的，如果left不在乘法表里，而满足第k小的条件。那么他一定是比乘法表中的第k小的值稍微大一点以至于count==K。不是count==K-1； 而 left取的是每次mid+1，是仅仅发生在mid的count<K的情况下，也就是说，如果left = mid+1，那么此时的mid一定不是第K小的数字。取left = mid+1，可以保证不漏掉数字。每次递增1. 即，left =mid+1 从左边逼近(注意，这样不会漏掉比要找的结果x还要小的数字)，right = mid从右边逼近（这个比较好理解。）
# 也就是说，每次取得的left，只可能是满足第K个数字中最小的那个，既然是最小的那个，一定是在乘法表当中的。 总结：我们可以认为有o1,o2,..on个数字满足count（oi）==K。其中，位于乘法表当中的数字一定是其中最小的。而left = mid+1时，count（mid）<K，这个时候mid不是第K小的数字，left=mid+1，只比mid大1可以保证不漏其他数字。当找到第一个满足count(mid)==K时（此时left=上一次的mid+1,保证最小，并且此后left不会变化）且right从右边逼近left时，可以得到结果。

class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        left = 1
        right = m * n + 1
        while left < right:
            mid = int((left + right) / 2)
            count = 0
            for i in range(1, m+1):
                count += min(int(mid / i), n)
            if count >= k:
                right = mid
            else:
                left = mid + 1
        return left

if __name__ == '__main__':

    a = Solution()
    print(a.findKthNumber(42,34,401))