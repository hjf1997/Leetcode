#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.size(), false);
//         for (int i=0; i<s.size(); i++){
//             for (const auto word: wordDict){
//                 if (i+1 >= word.size() && word == s.substr(i-word.size()+1, word.size())){
//                     dp[i] = i + 1 > word.size() ? dp[i-word.size()] : true;
//                 }
//             }
//         }
//         return dp.back();
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true; // base case

        for (int i=0; i<s.size(); i++){
            for (const auto word: wordDict){
                if (i+1 >= word.size() && word == s.substr(i-word.size()+1, word.size())){
                    dp[i+1] = dp[i-word.size()+1] || dp[i+1];
                }
            }
        }
        return dp.back();
    }
};

int main(){
    Solution sol;
    string s = "dogs";
    vector<string> wordDict = {"dog","s","gs"};
    cout << sol.wordBreak(s, wordDict) << endl;
    return 0;
}
