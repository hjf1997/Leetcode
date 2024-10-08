#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i=0;i<word1.size();i++) dp[i+1][0] = dp[i][0] + 1;
        for (int j=0;j<word2.size();j++) dp[0][j+1] = dp[0][j] + 1;

        for (int i=0;i<word1.size();i++)
            for (int j=0;j<word2.size();j++){
                if (word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j];
                else{
                    dp[i+1][j+1] = min({dp[i][j+1], dp[i+1][j], dp[i][j]}) + 1;
                }

            }
        return dp.back().back();
    }
};

int main(){
    Solution sol;
    string word1 = "";
    string word2 = "";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}