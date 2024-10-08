#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool ans;
        int left=1, right=nums[0];
        seg_search(nums, left, right, ans);
        return ans;
    }

    void seg_search(vector<int>& nums, int& left, int& right, bool& ans){
        if (right >= nums.size() - 1){
            ans = true;
            return;
        }
        // left and right are all included
        int max_index = right;
        int new_right = right, new_left = left;
        for (int i=left; i<=right; i++){
            if (i + nums[i] > max_index){
                max_index = i + nums[i];
                new_left = right + 1;
                new_right = max_index;
            }
        }
        if (new_right == right){
            ans = false;
            return;
        }
        seg_search(nums, new_left, new_right, ans);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,0};
    cout << sol.canJump(nums) << endl;
    return 0;
}