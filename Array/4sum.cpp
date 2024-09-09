#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        int left_anchor = 0, right_anchor = nums.size()-1;
        vector<vector<int>> ans;
        for (int left_anchor = 0; left_anchor < nums.size()-3; left_anchor++)
            for (int right_anchor = nums.size()-1; right_anchor > left_anchor+2; right_anchor--){
                if (left_anchor > 0 && nums[left_anchor] == nums[left_anchor-1]) continue;
                if (right_anchor < nums.size()-1 && nums[right_anchor] == nums[right_anchor+1]) continue;

                int left = left_anchor + 1, right = right_anchor - 1;
                while (left < right){
                    long long sum = static_cast<long long>(nums[left_anchor]) + nums[left] + nums[right] + nums[right_anchor];
                    if (sum < target) left += 1;
                    else if (sum > target) right -= 1;
                    else{
                        ans.push_back({nums[left_anchor], nums[left], nums[right], nums[right_anchor]});
                        do left += 1; while (left < right && nums[left] == nums[left-1]);
                        do right -= 1; while (left < right && nums[right] == nums[right+1]);
                    }
                }
            }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    long long target = 4000000000;
    vector<vector<int>> ans = sol.fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}