#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         //two-dimensional dp array
//         vector<vector<int>> dp;
//         // base case
//         dp.push_back({triangle[0][0]});

//         for (int i=1; i<triangle.size(); i++){
//             dp.push_back(vector<int>(i+1, 0));
//             for (int j=0; j<i+1; j++){
//                 if (j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];
//                 else if (j==i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
//                 else dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
//             }
//         }
//         return *min_element(dp.back().begin(), dp.back().end());
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //one-dimensional dp array
        vector<int> dp;
        dp.reserve(triangle.size());
        // base case
        dp.push_back(triangle[0][0]);

        for (int i=1; i<triangle.size(); i++){
            dp.push_back(0);
            int temp = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            for (int j=1; j<i+1; j++){
                int temp2 = dp[j];
                if (j==i) dp[j] = temp + triangle[i][j];
                else dp[j] = min(dp[j], temp) + triangle[i][j];
                temp = temp2;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution sol;
    vector<vector<int>> triangle = {{-10}, {1, 2}};
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}