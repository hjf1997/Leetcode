#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N^2)
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> dp(s.size(), vector<vector<string>>());
        // base case
        dp[0].push_back({s.substr(0, 1)});

        for (int i=1; i<s.size(); i++)
            for (int j=0; j<=i; j++){
                string candidate = s.substr(j, i-j+1);
                if (isPalindrome(candidate)){
                    // dp[j] + candidate
                    if (j==0) dp[i].push_back({candidate});
                    else{
                        for (int k=0; k<dp[j-1].size(); k++){
                            vector<string> temp = dp[j-1][k];
                            temp.push_back(candidate);
                            dp[i].push_back(temp);
                        }
                    }
                }
            }
        return dp.back();   
    }

    bool isPalindrome(string s){
        int l = 0, r = s.size() - 1;
        while (l <= r){
            if (s[l] == s[r]){
                l += 1;
                r -= 1;
            }
            else return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string p = "aaabaaac";
    vector<vector<string>> res = sol.partition(p);
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    // cout << sol.partition(p) << endl;
    return 0;
}

