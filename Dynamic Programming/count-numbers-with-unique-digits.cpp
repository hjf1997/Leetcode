#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) return 0;
        if (n == 0) return 1;
        vector<int> dp(n+1); 
        dp[0] = 1;
        dp[1] = 9;
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] * (11 - i);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(){
    Solution sol;
    int n = 2;
    cout << sol.countNumbersWithUniqueDigits(n) << endl;
    return 0;
}