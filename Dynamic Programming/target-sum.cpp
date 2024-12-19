#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       unordered_map<int, int> dp;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        dp[0] = 1;
        for (auto num: nums){
            unordered_map<int, int> dp_next;
            for (auto [i, count]: dp){
                dp_next[i + num] += count;
                dp_next[i - num] += count;
            }
            dp = dp_next;
        }
        return dp[target];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target = 1;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}