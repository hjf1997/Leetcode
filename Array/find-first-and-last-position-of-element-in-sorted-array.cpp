#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // special cases
        if (nums.size() == 0) return vector<int>{-1, -1};
        if (nums.size() == 1) return nums[0] == target ? vector<int>{0, 0} : vector<int>{-1, -1};

        int left_anchor = 0, right_anchor = nums.size()-1;
        int left = 0, right = nums.size()-1;
        // left_anchor, left, right, right_anchor
        while (left_anchor <= right_anchor){
            int mid = left_anchor + (right_anchor - left_anchor) / 2;
            if (nums[mid] == target){
                left = mid;
                right = mid;
                break;
            }
            if (nums[mid] < target){
                left_anchor = mid + 1;
            } else{
                right_anchor = mid - 1;
            }
        }
        if (nums[left] != target) return vector<int>{-1, -1};

        while (left_anchor < left){
            int mid = left_anchor + (left - left_anchor) / 2;
            if (nums[mid] == target) left = mid;
            else left_anchor = mid + 1;
            }
        while (right < right_anchor){
            int mid = right + (right_anchor - right) / 2 + 1;
            if (nums[mid] == target) right = mid;
            else right_anchor = mid - 1;   
        }
        return vector<int>{left, right};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,5,7,7,8,10,10};
    int target = 8;
    vector<int> ans = sol.searchRange(nums, target);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}