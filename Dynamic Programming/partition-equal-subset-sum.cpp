#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (auto num: nums)
            for (int i=sum; i>=0; i--){
                if (dp[i] && i + num <= sum){
                    dp[i+num] = true; 
                }
            }
        return dp.back();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,3,2,2,1};
    // vector<int> nums = {1,2,2,3,4};
    cout << sol.canPartition(nums) << endl;
    return 0;
}

//