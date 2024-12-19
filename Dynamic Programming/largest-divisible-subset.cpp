#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        for (int i=0; i<nums.size(); i++){
            dp[0][i] = 1; // 0 store number of nums
            dp[1][i] = i; // 1 index of previous larget factor
        }
        for (int i=1; i<nums.size(); i++)
            for (int j=i-1; j>=0; j--){
                if (nums[i] % nums[j] == 0 & dp[0][i] < dp[0][j] + 1){
                    dp[0][i] = dp[0][j] + 1;
                    dp[1][i] = j;
                }
            }
        int index = distance(dp[0].begin(), max_element(dp[0].begin(), dp[0].end()));
        vector<int> ans;
        while (index != dp[1][index]){
            ans.push_back(nums[index]);
            index = dp[1][index];
        }
        ans.push_back(nums[index]);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,8,10,240};
    vector<int> ans = sol.largestDivisibleSubset(nums);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
