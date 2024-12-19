#include <bits/stdc++.h>
using namespace std;
#include <numeric>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i=2; i<nums.size(); i++){
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = 1 + dp[i-1];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,1,3,5,7};
    cout << sol.numberOfArithmeticSlices(nums) << endl;
    return 0;
}