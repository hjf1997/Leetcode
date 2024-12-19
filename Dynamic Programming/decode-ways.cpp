#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        // this problem has many special cases to consider, like consecutive zeros
        if (s[0] == '0') return 0;
        dp[0] = 1; // two digits are a valid number
        dp[1] = 1;
        for (int i=1; i<s.size(); i++){
            if (s[i] != '0') dp[i+1] += dp[i];
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) < 27) dp[i+1] += dp[i-1];
        }
        return dp.back();
    }
};

int main(){
    Solution sol;
    string s = "0";
    cout << sol.numDecodings(s) << endl;
    return 0;
}