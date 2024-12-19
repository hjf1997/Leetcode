#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i=0; i<amount; i++)
            for (auto c: coins){
                if (i + 1 - c >= 0 && dp[i+1-c] != INT_MAX) dp[i+1] = min(dp[i+1], dp[i+1-c] + 1);
            }
        return dp.back() != INT_MAX ? dp.back() : -1;
    }
};

int main(){
    Solution sol;
    vector<int> coins = {2};
    int amount = 3;
    cout << sol.coinChange(coins, amount) << endl;
    return 0;
}