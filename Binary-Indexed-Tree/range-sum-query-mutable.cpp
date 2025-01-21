#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> nums;  // Original array
    vector<int> bit;   // Fenwick Tree

    NumArray(vector<int>& nums) {
        vector<int> bit(nums.size() + 1, 0); // one-indexed
        for (int i=1; i<=nums.size(); i++){
            int length = i & -i;
            bit[i] = accumulate(nums.begin() + i - length, nums.begin() + i, 0);
        }
        this->nums = nums;
        this->bit = bit;
    }
    
    void update(int index, int val) {
        index += 1;
        int delta = val - nums[index-1];
        nums[index - 1] = val;
        while (index < bit.size()){
            bit[index] += delta;
            index += index & - index;
        }
    }
    
    int sumRange(int left, int right) {
        left += 1;
        right += 1;
        // (0, right)
        int right_sum = 0;
        while (right >= 1){
            right_sum += bit[right];
            right -= right & - right;
        }
        // (0, left)
        int left_sum = 0;
        left -= 1;
        while (left >= 1){
            left_sum += bit[left];
            left -= left & -left;
        }
        return right_sum - left_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */