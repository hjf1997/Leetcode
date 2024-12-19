#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto coin: coins)
            for (int i=coin; i<=amount; i++)
                dp[i] += dp[i-coin];
        return dp[amount];
    }
};

int main(){
    Solution sol;
    vector<int> coins = {1, 2, 5};
    cout << sol.change(5, coins) << endl;
    return 0;
}