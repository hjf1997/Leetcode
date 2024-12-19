#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if (s1.size() == 0 && s2.size() == 0) return true;
//         vector<int> dp(s1.size()+1, -1);
//         int index = 0;
//         if (s3[0] == s2[0]) index = 1;
//         else if (s3[0] == s1[0]) dp[index] = 0; else return false;

//         for (int i=1; i<s3.size(); i++){
//             if (dp[index] == -1 && s1[dp[index-1] + 1] == s3[i]){
//                 dp[index] = dp[index-1] + 1;
//             }
//             else if (dp[index] == -1 && s1[dp[index-1] + 1] != s3[i]){
//                 if (s2[index] == s3[i]) index += 1;
//                 else return false;
//             }
//             else if (dp[index] != -1 && s1[dp[index] + 1] == s3[i]){
//                 dp[index] += 1;
//             }
//             else if (dp[index] != -1 && s1[dp[index] + 1] != s3[i]){
//                 if (s2[index] == s3[i]) index += 1;
//                 else return false;
//             }
//         }
//         return true;
//     }
// };

// class Solution {
// // two-dimensional array
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
//         dp[0][0] = true;
//         if (s1.size() + s2.size() != s3.size()) return false;
//         // base case
//         for (int i=1; i<=s1.size(); i++) dp[i][0] =  s1.substr(0, i) == s3.substr(0, i) ? true : false;
//         for (int i=1; i<=s2.size(); i++) dp[0][i] =  s2.substr(0, i) == s3.substr(0, i) ? true : false;

//         for (int i=0; i<s1.size(); i++)
//             for (int j=0; j<s2.size(); j++){
//                 dp[i+1][j+1] = dp[i][j+1] && s3[i+j+1] == s1[i] || dp[i+1][j] && s3[i+j+1] == s2[j];
//             }
//         return dp.back().back();
//     }
// };

class Solution {
// one-dimensional array
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (!s1.empty() && !s2.empty() && s2.back() != s3.back() && s1.back() == s3.back()) swap(s1, s2);
        vector<bool> dp(s2.size()+1, false);
        dp[0] = 1;
        for (int i=1; i<=s2.size(); i++) dp[i] = s2.substr(0, i) == s3.substr(0, i) ? true : false;
        if (s1.size() + s2.size() != s3.size()) return false;

        for (int i=0; i<s1.size(); i++){
            dp[0] = s1.substr(0, i+1) == s3.substr(0, i+1) ? true : false;
            for (int j=0; j<s2.size(); j++){
                dp[j+1] = dp[j+1] && s3[i+j+1] == s1[i] || dp[j] && s3[i+j+1] == s2[j];
            }
        }
        return dp.back();
    }
};


int main(){
    Solution sol;
    string s1 = "a";
    string s2 = "b";
    string s3 = "ab";
    cout << sol.isInterleave(s1, s2, s3) << endl;
    return 0;
}