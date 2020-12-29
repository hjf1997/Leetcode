from typing import List
# 1027ms 12.23%
# 14.2MB 28.06%
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        height = len(grid)
        width = len(grid[0])
        t_left = 0
        t_right = height * width - 1
        while t_left < t_right:
            t_mid = int((t_left + t_right) / 2)
            if self.buildunion(grid, height, width, t_mid):
                t_right = t_mid
            else:
                t_left = t_mid + 1
        return t_left

    def buildunion(self, grid, height, width, t):
        parents = []
        rank = []
        # init parents matrix and the depth of the union tree
        for i in range(height):
            parents.append([])
            rank.append([])
            for j in range(width):
                parents[i].append([i, j])
                rank[i].append(1)

        # get neighbor
        neighbor = []
        for i in range(height):
            for j in range(width):
                if t >= grid[i][j]:
                    if i < height - 1 and t >= grid[i+1][j]:
                        neighbor.append([i, j, i+1, j])
                    if j < width - 1 and t >= grid[i][j+1]:
                        neighbor.append([i, j, i, j+1])

        # union
        for i in range(len(neighbor)):
            parents, rank = self.unionele(parents, rank, neighbor[i][:2], neighbor[i][2:])

        return self.isconnected(parents, [0,0], [height-1, width-1])

    def unionele(self, parents, rank, p, q):
        p_root = self.find(parents, p)
        q_root = self.find(parents, q)

        if p_root == q_root:
            return parents, rank
        if rank[p_root[0]][p_root[1]] < rank[q_root[0]][q_root[1]]:
            parents[p_root[0]][p_root[1]] = q_root
        elif rank[p_root[0]][p_root[1]] > rank[q_root[0]][q_root[1]]:
            parents[q_root[0]][q_root[1]] = p_root
        else:
            parents[p_root[0]][p_root[1]] = q_root
            rank[p_root[0]][p_root[1]] += 1
        return parents, rank

    def isconnected(self, parents, p, q):
        return self.find(parents, p) == self.find(parents, q)

    def find(self, parents, p):
        while p != parents[p[0]][p[1]]:
            parents[p[0]][p[1]] = parents[parents[p[0]][p[1]][0]][parents[p[0]][p[1]][1]]
            p = parents[p[0]][p[1]]
        return p

if __name__ == '__main__':
    a = Solution()
    print(a.swimInWater([[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]))

