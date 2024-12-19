#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // try to simplify the problem
        int start=0, end;
        int max_num = nums[0];
        bool has_zero = false;
        for (int i=0; i<nums.size(); i++){
            if (nums[start]==0){
                has_zero = true;
                start += 1;
                continue;
            }
            if (nums[i]==0){
                has_zero = true;
                end = i-1;
                max_num = max(max_num, subNums(vector<int>(nums.begin()+start, nums.begin()+end+1)));
                start = i+1;
            }
        }
        if (start < nums.size()){
            max_num = max(max_num, subNums(vector<int>(nums.begin()+start, nums.end())));
        }
        return has_zero ? max(max_num, 0) : max_num;
    }

    int subNums(const vector<int>& nums){
        int prod = nums[0], max_1 = nums[0];
        for (int i=1; i<nums.size(); i++){
            prod *= nums[i];
            max_1 = max(max_1, prod);
        }
        int max_2 = nums.back();
        prod = nums.back();
        for (int i=nums.size()-2; i>=0; i--){
            prod *= nums[i];
            max_2 = max(max_2, prod);
        }
        return max(max_1, max_2);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2};
    // {-2, -3}

    cout << sol.maxProduct(nums) << endl;
    return 0;
}