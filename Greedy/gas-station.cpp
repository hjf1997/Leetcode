#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> remain_gas;
        remain_gas.push_back(gas[0]-cost[0]);
        for (int i=1; i<gas.size(); i++){
            remain_gas.push_back(remain_gas[i-1]+gas[i]-cost[i]);
        }
        if (remain_gas.back() < 0) return -1;

        auto min_value = min_element(remain_gas.begin(), remain_gas.end());
        int min_index = distance(remain_gas.begin(), min_value);
        return (min_index + 1) % gas.size();
    }
};

int main() {
    Solution sol;
    vector<int> gas = {5,8,2,8};
    vector<int> cost = {6,5,6,6};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}