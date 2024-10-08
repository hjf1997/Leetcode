#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++){
            if (sub.back() > nums[i]){
                auto pos = lower_bound(sub.begin(), sub.end(), nums[i]);
                *pos = nums[i];
            }
            else if (sub.back() < nums[i]) sub.push_back(nums[i]);
        }
        return sub.size();
    }
};


int main(){
    Solution sol;
    vector<int> nums = {7,7,7,7,7};
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}