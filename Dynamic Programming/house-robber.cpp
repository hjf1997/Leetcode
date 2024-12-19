#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i=1; i<nums.size(); i++){
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }
        return dp.back();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,2,4,2,2,2};
    cout << sol.rob(nums) << endl;
    return 0;
}