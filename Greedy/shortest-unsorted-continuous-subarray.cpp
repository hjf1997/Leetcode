#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=nums.size()-1,right=0;
        for (int i=1;i<nums.size();i++){
            if (nums[i-1]>nums[i]) {
                left = min(left, i-1);
                right = max(right,i);
            }
        }
        if (left==nums.size()-1 && right==0) return 0;
        int min_value = *min_element(nums.begin() + left, nums.begin() + right + 1);
        int max_value = *max_element(nums.begin() + left, nums.begin() + right + 1);
        while (left>0){
            if (min_value < nums[left-1]) left--;
            else
                break;
        }
        while (right<nums.size()-1){
            if (max_value > nums[right+1]) right++;
            else
                break;
        }
        return right - left + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,6,4,1,8,16,9,15};
    cout << sol.findUnsortedSubarray(nums) << endl;
    return 0;
}