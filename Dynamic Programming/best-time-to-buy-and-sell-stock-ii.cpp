#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold_index = -1, profit=0;
        for (int i=0; i<prices.size()-1; i++){
            if (prices[i+1] > prices[i] && hold_index == -1){ // buy
                hold_index = i;
            }
            else if (prices[i+1] < prices[i] && hold_index != -1){ // sell
                profit += prices[i] - prices[hold_index];
                hold_index = -1;
            }
            if (i==prices.size()-2 && hold_index != -1){ // last sell
                profit += prices[i+1] - prices[hold_index];
                hold_index = -1;
            }
        }
        return profit > 0 ? profit : 0;
    }
};

int main(){
    Solution sol;
    vector<int> p = {1,2,3,4,5,3};
    cout << sol.maxProfit(p) << endl;
    return 0;
}

