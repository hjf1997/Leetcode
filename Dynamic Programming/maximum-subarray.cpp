#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {102, -1, -2, -3, 100};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}