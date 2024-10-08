#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int count = 1;
        int left = 1, right = nums[0];
        seg_search(nums, left, right, count);
        return count;
    }

    void seg_search(vector<int>& nums, int& left, int& right, int& count){
    if (right >= nums.size() - 1)
        return;
    int max_index = right;
    int new_right = right, new_left = left;
    for (int i=left; i<=right; i++){
        if (i + nums[i] > max_index){
            max_index = i + nums[i];
            new_left = right + 1;
            new_right = max_index;
        }
    }
    count++;
    seg_search(nums, new_left, new_right, count);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,0};
    cout << sol.jump(nums) << endl;
    return 0;
}