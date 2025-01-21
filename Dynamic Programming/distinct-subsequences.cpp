class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));
        // base cases
        dp[0][0] = s[0] == t[0] ? 1 : 0;
        for (int i=1; i<s.size(); i++) dp[0][i] = t[0] == s[i] ? dp[0][i-1] + 1 : dp[0][i-1];

        for (int i=1; i<t.size(); i++)
            for (int j=i; j<s.size(); j++){
                dp[i][j] = t[i] == s[j] ? (1LL *  dp[i-1][j-1] + dp[i][j-1]) % INT_MAX : dp[i][j-1];
            }
        return dp[t.size()-1][s.size()-1];
    }
};