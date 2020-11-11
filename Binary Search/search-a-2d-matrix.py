from typing import List
# 36ms 90.35%
# 13.6MB 79.27%
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        up, low = 0, len(matrix)-1
        while up < low:
            mid = int((up + low) / 2 + 0.5)
            if matrix[mid][0] < target:
                up = mid
            elif matrix[mid][0] > target:
                low = mid - 1
            else:
                up = mid
                break

        left, right = 0, len(matrix[0])-1
        sub_matrix = matrix[up]
        while left <= right:
            mid = int((left + right) / 2)
            if sub_matrix[mid] < target:
                left = mid + 1
            elif sub_matrix[mid] > target:
                right = mid - 1
            else:
                return True
        return False

if __name__ == '__main__':

    a = Solution()
    print(a.searchMatrix([[1,1,3,4,5,6],[7,8,9,10,11],[13,15,17,89,100,101]], 1))

