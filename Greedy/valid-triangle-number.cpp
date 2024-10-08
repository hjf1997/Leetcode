#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int begin_index = 0, count=0;
        // special case 
        for (int i=0;i<nums.size();i++){
            if (nums[i] == 0) begin_index += 1;
            else break;
        }
        if (begin_index == nums.size()) return 0;

        int left=begin_index, right=nums.size()-1;
        for (int l=left; l<right-1; l++){
            int r = right, index=r-1, current_count=0;
            while(l < r-1){
                while (index >= l+1){
                    if (nums[l] + nums[index] > nums[r]) { 
                        current_count += 1;
                        index -= 1;
                    }
                    else break;
                }
                count += current_count;
                r -= 1;
                current_count -= 1;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,2,3,4};
    cout << sol.triangleNumber(nums) << endl;
    return 0;
}

