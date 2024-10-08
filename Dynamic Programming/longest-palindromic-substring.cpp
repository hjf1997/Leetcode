#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int max_length = 1;
        string ans = s.substr(0, 1);
        // init
        for (int i=0; i<s.size(); i++){
            dp[i][i] = 1; // delta 1
            if ((i<s.size()-1) && (s[i] == s[i+1])) {
                dp[i][i+1] = 1; // delta 2
                max_length = 2;
                ans = s.substr(i, 2);
            }
        }

        for (int delta=2; delta<s.size(); delta++)
            for (int i=0; i<s.size()-delta; i++){
                if ((s[i] == s[i+delta]) && dp[i+1][i+delta-1] > 0) {
                    dp[i][i+delta] = 1;
                    if (delta + 1 > max_length){
                        max_length = delta + 1;
                        ans = s.substr(i, delta+1);
                    }
                }
            }
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "wertabcdefggfedcbaxxabcba";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}