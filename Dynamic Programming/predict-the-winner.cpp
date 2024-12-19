#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool predictTheWinner(vector<int>& nums) {
//         // batcktracking + prunning
//         // But this is wrong
//         // this is just to search a way whether A can win
//         bool ans=false;
//         int half_sum = accumulate(nums.begin(), nums.end(), 0) / 2;
//         search(nums, 0, 0, true, ans, half_sum);
//         return ans;
//     }

//     void search(const vector<int>& nums, int sum_a, int sum_b, bool turn_a, bool& ans, int& half_sum){
//         if (nums.size() == 0){
//             if (sum_a >= sum_b) ans = true;
//         }
//         if (ans) return; // prunning
//         if (sum_a > half_sum) ans=true;
//         if (sum_b > half_sum) return;

//         if (turn_a){
//             search(vector<int>(nums.begin()+1, nums.end()), sum_a+nums[0], sum_b, false, ans, half_sum);
//             search(vector<int>(nums.begin(), nums.end()-1), sum_a+nums.back(), sum_b, false, ans, half_sum);
//         }else{
//             search(vector<int>(nums.begin()+1, nums.end()), sum_a, sum_b+nums[0], true, ans, half_sum);
//             search(vector<int>(nums.begin(), nums.end()-1), sum_a, sum_b+nums.back(), true, ans, half_sum);
//         }
//     }
// };

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i=0; i<nums.size(); i++) dp[i][i] = nums[i];
        bool turn_a = true;
        for (int len=1; len<nums.size(); len++)
            for (int i=0; i+len<nums.size(); i++){
                dp[i][i+len] = max(nums[i] - dp[i+1][i+len], nums[i+len] - dp[i][i+len-1]);
            }   
        return dp[0].back() >= 0;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,5,2};
    cout << sol.predictTheWinner(nums) << endl;
    return 0;
}