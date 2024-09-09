#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        for (int i = 0; i < candidates.size(); i++){
            search(candidates, candidates[i], path, target, ans);
        }
        return ans;
    }

    void search(vector<int>& candidates, int num, vector<int>& path, int target, vector<vector<int>>& ans){
        // should judge the condition before calling the function instead of in the function
        int last_value = path.size() == 0 ? 0 : path.back();
        if (last_value > num) return;
        int sum = accumulate(path.begin(), path.end(), 0) + num;
        if (sum > target) return;
        if (sum == target){
            path.push_back(num);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        if (sum < target){
            path.push_back(num);
            for (int i = 0; i < candidates.size(); i++){
                search(candidates, candidates[i], path, target, ans);
            }
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 4, 5, 6};
    int target = 9;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}