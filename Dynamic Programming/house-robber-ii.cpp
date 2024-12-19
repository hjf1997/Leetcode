#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         vector<int>::iterator max_index = max_element(nums.begin(), nums.end());
//         int index = distance(nums.begin(), max_index);
//         vector<int> dp(nums.size());
//         dp[index] = nums[index];
//         for (int i=index+1; i<index+nums.size()-1; i++){
//             dp[i%nums.size()] = max(dp[(i-2+nums.size())%nums.size()]+nums[i%nums.size()], dp[(i-1+nums.size())%nums.size()]);
//         }
//         return dp[(index-2+nums.size())%nums.size()];
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(cal_max(nums1), cal_max(nums2));
    }

    int cal_max(vector<int>& nums){
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
    vector<int> nums = {1,7,9,4};
    cout << sol.rob(nums) << endl;
    return 0;
}