#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m=mat.size(), n=mat[0].size();
//         bool changed = true;
//         vector<vector<int>> dp(m, vector<int>(n, 100000));
//         for (int i=0; i<m; i++)
//             for (int j=0; j<n; j++){
//                 if (mat[i][j] == 0){
//                     dp[i][j] = 0;
//                 }
//             }        
//         while (changed){
//             changed = false;
//             for (int i=0; i<m; i++)
//                 for (int j=0; j<n; j++){
//                     int temp = dp[i][j];
//                     if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); // up 
//                     if (i < m-1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1); // low
//                     if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); // left
//                     if (j < n-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1); // right
//                     if (temp != dp[i][j]) changed = true;
//                 }
//         }
//         return dp;
//     }
// };


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // BFS
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        while (!q.empty()){
            auto [i, j] = q.front(); q.pop();
            if (i > 0 && ans[i-1][j] == -1) {ans[i-1][j] = ans[i][j] + 1; q.emplace(i-1, j);}
            if (i < m - 1 && ans[i+1][j] == -1) {ans[i+1][j] = ans[i][j] + 1; q.emplace(i+1, j);}
            if (j > 0 && ans[i][j-1] == -1) {ans[i][j-1] = ans[i][j] + 1; q.emplace(i, j-1);}
            if (j < n - 1 && ans[i][j+1] == -1) {ans[i][j+1] = ans[i][j] + 1; q.emplace(i, j+1);}
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat = {{0,1,1,0,1,0,1,0,1,0},{1,1,1,0,0,0,1,0,0,1},{0,1,1,1,0,1,1,0,1,1},{1,1,1,1,0,1,1,1,1,0},{1,0,1,1,1,1,1,1,1,1},{1,1,1,1,0,0,1,0,1,1},{1,1,0,1,0,0,1,1,1,1},{1,1,0,1,0,0,1,0,0,0},{0,0,1,0,1,0,1,1,1,0},{1,1,1,1,0,1,1,0,1,1}};
    vector<vector<int>> res = sol.updateMatrix(mat);
    // cout the input matrix
    for (auto row: mat){
        for (int x: row) cout << x << " ";
        cout << endl;
    }
    cout << endl;
    for (auto row: res){
        for (int x: row) cout << x << " ";
        cout << endl;
    }
    return 0;
}