#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int max_square = sqrt(n);
        vector<int> dp(n+1, 100001);
        dp[0] = 0;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=max_square; j++){
                if (i - j*j < 0) break;
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        return dp.back();
    }
};

int main(){
    Solution sol;
    int n = 10000;
    cout << sol.numSquares(n) << endl;
    return 0;
}