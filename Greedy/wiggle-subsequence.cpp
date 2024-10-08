#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] != nums[i+1]) break;
            if (i == nums.size()-2) return 1;
        }

        int count=1, index=0;
        bool up_flag = true;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] != nums[i+1]){
                up_flag = nums[i] < nums[i+1] ? true:false;
                break;
            }
        }

        while (index<nums.size()-1){
            index = turning_point(index, nums, up_flag);
            count+=1;
            up_flag = !up_flag;
        }
        return count;
    }
    // pay attention to boundary case
    int turning_point(int index, vector<int>& nums, bool up){
        int anchor = nums[index];
        for (int i=index+1; i<nums.size(); i++){
            if (up){
                if (anchor > nums[i]) return i-1;
            }
            else{
                if (anchor < nums[i]) return i-1;
            }
            anchor = nums[i];
        }
        return nums.size()-1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    cout << sol.wiggleMaxLength(nums) << endl;
    return 0;
}