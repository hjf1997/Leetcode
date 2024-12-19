#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[0][i][j] = matrix[i][j] - '0';
                ans = max(ans, dp[0][i][j]);
            }
        }

        for (int l=2; l<=min(m, n); l++){
            for (int i=0; i<m-l+1; i++)
                for (int j=0; j<n-l+1; j++){
                    if (dp[0][i][j+1] && dp[0][i+1][j] && matrix[i][j] - '0' && matrix[i+l-1][j+l-1] - '0'){
                        dp[1][i][j] = 1;
                        ans = max(ans, l*l);
                    }
                }
            dp[0] = dp[1];
            dp[1] = vector<vector<int>>(m, vector<int>(n, 0)); // remember to clear the matrix 
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','1','1','1'}};
    cout << sol.maximalSquare(matrix) << endl;
    return 0;
}