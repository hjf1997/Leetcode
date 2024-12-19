#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findSubstringInWraproundString(string s) {
//         // Memory Limit Exceeded
//         unordered_set<string> ans;
//         vector<vector<string>> dp(s.size(), vector<string>());
//         dp[0].push_back(s.substr(0, 1));
//         ans.insert(s.substr(0, 1));

//         for (int i=1; i<s.size(); i++){
//             dp[i].push_back(s.substr(i, 1));
//             ans.insert(s.substr(i, 1));
//             if ((s[i] - s[i-1] + 26) % 26 == 1){
//                 for (auto sub: dp[i-1]){
//                     dp[i].push_back(sub+s[i]);
//                     ans.insert(sub+s[i]);
//                 }
//             }
//         }
//         return ans.size();
//     }
// };

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        map<char, int> ans;
        for (int i=0; i<26; i++){
            ans['a'+i] = 0;
        }
        int dp = 1;
        ans[s[0]] = 1;
        for (int i=1; i<s.size(); i++){
            if ((s[i] - s[i-1] + 26) % 26 == 1){
                dp += 1;
            } else {
                dp = 1;
            }
            ans[s[i]] = max(ans[s[i]], dp);
        }
        int sum = 0;
        for (auto [key, value]: ans){
            sum += value;
        }
        return sum;
    }
};

int main(){
    Solution sol;
    string s = "abcd";
    cout << sol.findSubstringInWraproundString(s) << endl;
    return 0;
}