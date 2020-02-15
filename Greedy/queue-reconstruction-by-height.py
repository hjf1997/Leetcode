from typing import List
# 124ms 41.39%
# 13.5MB 35.58%
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        if len(people) == 0:
            return []
        ans = []
        self.quickSort(people, 0, len(people)-1)
        ans.append(people[-1])
        for i in range(len(people)-2, -1, -1):
            ans.insert(people[i][1], people[i])
        return ans

    def quickSort(self, list, left, right):
        if left >= right:
            return
        k0 = left
        k1 = right
        temp = list[left]
        while left < right:
            while (list[right][0] > temp[0] or (list[right][0] == temp[0] and list[right][1] < temp[1])) and left < right:
                right -= 1
            list[left] = list[right]
            while (list[left][0] < temp[0] or (list[left][0] == temp[0] and list[left][1] > temp[1])) and left < right:
                left += 1
            if left == right:
                list[right] = temp
            else:
                list[right] = list[left]
        self.quickSort(list, k0, left-1)
        self.quickSort(list, right+1, k1)

a = Solution()
l = [[9,0],[7,0],[1,9],[3,0],[2,7],[5,3],[6,0],[3,4],[6,2],[5,2]]
ans = a.reconstructQueue(l)
print(ans)
