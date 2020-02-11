from typing import List
import random

class Solution:

    def candy(self, ratings: List[int]) -> int:
        candy_list = [1]
        for i in range(1, len(ratings)):

            if ratings[i] > ratings[i-1]:
                candy_list.append(candy_list[-1]+1)
            else:
                candy_list.append(1)
                for j in range(len(candy_list)-1, 0, -1):
                    if ratings[j-1] > ratings[j] and candy_list[j-1] == candy_list[j]:
                        candy_list[j - 1] += 1
                    else:
                        break
        return sum(candy_list)

    def check(self, ratings, candys):
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1] and candys[i] <= candys[i-1]:
                print('False')
                return

a = Solution()
l = [4,4,3,3,3,2,2]
print(a.candy(l))
# for i in range(500):
#     rats = random.choices(range(1,100), k=50)
#     print(a.candy(rats))
