#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        vector<bool> choose(nums.size(), false);
        vector<vector<int>> ans;
        search(nums, permutation, choose, ans);
        return ans;   
    }

    void search(vector<int>& nums, vector<int>& permutation, vector<bool>& choose, vector<vector<int>>& ans){
        if (permutation.size() == nums.size()){
            ans.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (choose[i]) continue;
            choose[i] = true;
            permutation.push_back(nums[i]);
            search(nums, permutation, choose, ans);
            permutation.pop_back();
            choose[i] = false;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3};
    vector<vector<int>> ans = sol.permute(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}