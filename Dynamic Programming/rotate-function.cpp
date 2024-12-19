#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur = 0, sum = 0;
        for (int i=0; i<nums.size(); i++)   {
            cur += i * nums[i];
            sum += nums[i];
        }
        int ans = cur;
        for (int i=nums.size() - 1; i>0; i--){
            cur = cur + sum - nums.size() * nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4, 3, 2, 6};
    cout << sol.maxRotateFunction(nums) << endl;
    return 0;
}