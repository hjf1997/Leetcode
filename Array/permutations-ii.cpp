#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        set<vector<int>> s(ans.begin(), ans.end());
        ans.assign(s.begin(), s.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1};
    vector<vector<int>> ans = sol.permuteUnique(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}