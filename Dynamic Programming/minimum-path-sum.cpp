#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int const INF = 1e9;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INF));
        dp[0][0] = grid[0][0];
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (i>0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                }
                if (j>0){
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{3}};
    cout << sol.minPathSum(grid) << endl;
    return 0;
}