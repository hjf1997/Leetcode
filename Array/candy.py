from typing import List
import random
# 184ms 89.93%
# 15.4MB 72.44%
class Solution:

    def candy(self, ratings: List[int]) -> int:
        candy_list = [1 for i in range(len(ratings))]

        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                candy_list[i] += candy_list[i-1]

        for i in range(len(ratings)-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                candy_list[i] = max(candy_list[i+1] + 1, candy_list[i])
        return sum(candy_list)

a = Solution()
l = [1,0,2]
print(a.candy(l))
# for i in range(500):
#     rats = random.choices(range(1,100), k=50)
#     print(a.candy(rats))
