#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i=2; i<=n; i++)
            for (int j=1; j<i; j++){
                dp[i] = max(dp[i], max(j, dp[j]) * (i - j));
            }
        return dp.back();
    }
};

int main(){
    Solution sol;
    cout << sol.integerBreak(10) << endl;
    return 0;
}