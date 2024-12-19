#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        ans = to_string(nums[0]);
        if (nums.size() == 1) return ans;
        if (nums.size() == 2) return ans + "/" + to_string(nums[1]);
        ans += "/(" + to_string(nums[1]);
        for (int i=2; i<nums.size(); i++) ans += "/" + to_string(nums[i]);
        ans += ")";
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1000,100,10,2};
    cout << sol.optimalDivision(nums) << endl;
    return 0;
}