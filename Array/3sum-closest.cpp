#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 10e5;  // Pay attention to the range
        for (int anchor = 0; anchor < nums.size() - 2; anchor++){
            int left = anchor +1, right = nums.size()-1;
            while (left < right){
                int sum = nums[anchor] + nums[left] + nums[right];
                ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                if (sum < target){
                    left += 1;
                } else{
                    right -= 1;
                }
            }
        }
    return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1};
    int target = -100;
    int ans = sol.threeSumClosest(nums, target);
    cout << ans << endl;
    return 0;
}