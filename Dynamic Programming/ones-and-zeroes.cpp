#include <bits/stdc++.h>
using namespace std;

// class Solution {
// // version one
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<int> ones(strs.size(), 0), zeros(strs.size(), 0);
//         for (int i=0; i<strs.size(); i++)
//             for (auto c: strs[i]){
//                 if (c == '0') zeros[i] += 1;
//                 if (c == '1') ones[i] += 1;
//             }
//         // m is zero / n is one
//         vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

//         for (int i=0; i<strs.size(); i++)
//             for (int mm=0; mm<=m; mm++)
//                 for (int nn=0; nn<=n; nn++){
//                     dp[i+1][mm][nn] = dp[i][mm][nn];
//                     if (mm-zeros[i] >= 0 && nn-ones[i] >= 0){
//                         dp[i+1][mm][nn] = max(dp[i+1][mm][nn], dp[i][mm-zeros[i]][nn-ones[i]] + 1);
//                     }
//                 }
//         return dp.back().back().back();
//     }
// };

// class Solution {
// // version two
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

//         for (int i=0; i<strs.size(); i++){
//             int zeros = 0, ones = 0;
//             for (auto c: strs[i]){
//                 if (c == '0') zeros += 1;
//                 if (c == '1') ones += 1;
//             }
//             for (int mm=0; mm<=m; mm++)
//                 for (int nn=0; nn<=n; nn++){
//                     dp[i+1][mm][nn] = dp[i][mm][nn];
//                     if (mm-zeros >= 0 && nn-ones >= 0){
//                         dp[i+1][mm][nn] = max(dp[i+1][mm][nn], dp[i][mm-zeros][nn-ones] + 1);
//                     }
//                 }
//         }
//         return dp.back().back().back();
//     }
// };


class Solution {
// version three
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i=0; i<strs.size(); i++){
            int zeros = 0, ones = 0;
            for (auto c: strs[i]){
                if (c == '0') zeros += 1;
                if (c == '1') ones += 1;
            }
            for (int k=m; k>=0; k--)
                for (int j=n; j>=0; j--){
                    if (k + zeros <= m && j + ones <= n){
                        dp[k+zeros][j+ones] = max(dp[k+zeros][j+ones], dp[k][j] + 1);
                    }
                }
        }
        return dp.back().back();
    }
};

int main(){
    Solution s;
    vector<string> strs = {"10","0","1"};
    int m = 1, n = 1;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}