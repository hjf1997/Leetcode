#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size(), horizontal = 0, ans = 0;
//         vector<int> vertical(n, 0);
//         vector<vector<pair<int, int>>> dp(n);

//         for (int i=0; i<n; i++){
//             if (matrix[0][i] == '1'){
//                 horizontal += 1;
//                 dp[i].emplace_back(horizontal, 1);
//                 ans = max(ans, horizontal);
//             } 
//             else horizontal = 0;
//             vertical[i] = matrix[0][i] - '0';
//         }

//         for (int i=1; i<m; i++){
//             vector<pair<int, int>> old_element = dp[0];
//             // update j == 0
//             dp[0].clear();
//             if (matrix[i][0] == '1'){
//                 vertical[0] += 1;
//                 dp[0].emplace_back(1, vertical[0]);
//                 ans = max(ans, vertical[0]);
//                 horizontal = 1;
//             } else{
//                 horizontal = 0;
//                 vertical[0] = 0;
//             }
//             // update j > 0
//             for (int j=1; j<n; j++){
//                 vector<pair<int, int>> temp = dp[j];
//                 dp[j].clear();
//                 if (matrix[i][j] == '1'){
//                     vertical[j] += 1;
//                     horizontal += 1;
//                     dp[j].emplace_back(1, vertical[j]);
//                     dp[j].emplace_back(horizontal, 1);
//                     ans = max(ans, max(vertical[j], horizontal));
//                     for (auto cand: old_element){
//                         int width = min(horizontal, cand.first + 1);
//                         int height = min(vertical[j], cand.second + 1);
//                         dp[j].emplace_back(width, height);
//                         ans = max(ans, width * height);
//                     }
//                 } else{
//                     vertical[j] = 0;
//                     horizontal = 0;
//                 }
//                 old_element = temp;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> max_width(m, vector<int>(n, 0)), 
            up_max_height(m, vector<int>(n, 0)), down_max_height(m, vector<int>(n, 0));
        stack<int> temp;

        // get max width
        for (int i=0; i<m; i++){
            max_width[i][0] = matrix[i][0] - '0';
            for (int j=1; j<n; j++) max_width[i][j] = matrix[i][j] == '1' ? max_width[i][j-1] + 1 : 0;
        }
        
        // get max height
        for (int j=0; j<n; j++){
            temp = stack<int>();
            for (int i=0; i<m; i++){
                while (!temp.empty() && max_width[i][j] <= max_width[temp.top()][j]) temp.pop();
                int up = temp.empty() ? -1 : temp.top();
                up_max_height[i][j] = i - up ;
                temp.push(i);
            }

            temp = stack<int>();
            for (int i=m-1; i>=0; i--){
                while (!temp.empty() && max_width[i][j] <= max_width[temp.top()][j]) temp.pop();
                int down = temp.empty() ? m : temp.top();
                down_max_height[i][j] = down - i;
                temp.push(i);
            }
        }

        int ans = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++){
                ans = max(ans, (up_max_height[i][j] + down_max_height[i][j] - 2) * max_width[i][j]);
            }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','1','1','1'}};
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}