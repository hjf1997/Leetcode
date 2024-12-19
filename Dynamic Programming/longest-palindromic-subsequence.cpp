#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i=0; i<s.size(); i++) dp[i][i] = 1;
        for (int i=0; i<s.size()-1; i++){
            if (s[i] == s[i+1]) dp[i][i+1] = 2;
            else dp[i][i+1] = 1;
        }

        for (int len=2; len<s.size(); len++)
            for (int i=0; i+len<s.size(); i++){
                if (s[i] == s[i+len]) dp[i][i+len] = dp[i+1][i+len-1] + 2;
                else dp[i][i+len] = max(dp[i+1][i+len], dp[i][i+len-1]);
            }
        return dp[0][s.size()-1];
    }
};

int main(){
    Solution sol;
    string s = "asbgchdjckbla";
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}