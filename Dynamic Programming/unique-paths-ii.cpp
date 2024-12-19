#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++){
                if (i>0) dp[i][j] = obstacleGrid[i][j] == 0 ? (dp[i-1][j] + dp[i][j]) : 0;
                if (j>0) dp[i][j] = obstacleGrid[i][j] == 0 ? (dp[i][j-1] + dp[i][j]) : 0;
            }
        return dp.back().back();
    }
};

int main(){
    Solution sol;
    vector<vector<int>> obstacle = {{1}};
    cout << sol.uniquePathsWithObstacles(obstacle) << endl;
    return 0;
}