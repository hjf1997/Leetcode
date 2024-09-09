#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        // search the split
        int left = 0, right = nums.size()-1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        // search the target
        int min_index, max_index;
        if (left == 0) min_index = 0, max_index = nums.size()-1;
        else min_index = left, max_index = left - 1;
        if (target > nums[max_index] || target < nums[min_index]) return -1;

        if (target > nums[nums.size()-1]){
            left = 0;
            right = right - 1;
        } else{
            left = left;
            right = nums.size()-1;
        }
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3};
    int target = 2;
    int ans = sol.search(nums, target);
    cout << ans << endl;
    return 0;
}