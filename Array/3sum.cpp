#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<vector<int>> ans_vec;
        int anchor = 0;
        while (anchor < nums.size() - 2){
            int left = anchor + 1, right = nums.size()-1;
            while (left < right){
                if (nums[anchor] + nums[left] + nums[right] == 0){
                    ans.insert({nums[anchor], nums[left], nums[right]});
                    left += 1;
                }
                else if (nums[anchor] + nums[left] + nums[right] < 0){
                    left += 1;
                } else{
                    right -= 1;
                }
            }
            anchor += 1;
        }
        for (auto it = ans.begin(); it != ans.end(); it++){
            ans_vec.push_back(*it);
        }
        return ans_vec;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, -1, -1, 0 , 1, 2, 3};
    vector<vector<int>> ans = sol.threeSum(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}