#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     // O(N^2)
//     int maxProfit(vector<int>& prices) {
//         vector<int> dp_buy(prices.size(), 0);
//         vector<int> dp_sell(prices.size(), 0);
//         for (int i=1; i<prices.size(); i++)
//             for (int j=0; j<i; j++){
//                 if (j < i-1) dp_buy[i] = max(dp_buy[i], dp_sell[j]);
//                 dp_sell[i] = max(dp_sell[i], dp_buy[j] + prices[i] - prices[j]);
//         }
//         return *max_element(dp_sell.begin(), dp_sell.end());
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maintain(2, 0), buy(2, 0), sell(2, 0);
        maintain[0] = 0;
        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i=1; i<prices.size(); i++){
            maintain[1] = max(maintain[0], sell[0]);
            buy[1] = max(buy[0], maintain[0] - prices[i]);
            sell[1] = buy[0] + prices[i];
            maintain[0] = maintain[1], buy[0] = buy[1], sell[0] = sell[1];
            maintain[1] = 0, buy[1] = 0, sell[1] = 0;
        }
        return max(maintain[0], sell[0]);
    }
};

int main(){
    Solution sol;
    vector<int> prices = {5,100,120,20,80};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}