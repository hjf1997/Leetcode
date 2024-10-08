#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 1) return candidates[0] == target ? vector<vector<int>>{{target}} : vector<vector<int>>{};
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        search(candidates, target, path, 0, ans);
        return ans;
    }

    void search(vector<int>& candidates, int target, vector<int>& path, int current_index, vector<vector<int>>& ans){
        if (current_index >= candidates.size()) return; // this line is important
        int num = target - candidates[current_index];
        if (num == 0) {
            path.push_back(candidates[current_index]);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        if (num < 0) return;
        if (num > 0){
            int delta = 1;
            for (int i = current_index+1; i < candidates.size(); i++){
                if (candidates[i] == candidates[current_index]) delta++;
                else break;
            }
            search(candidates, target, path, current_index+delta, ans); // not use the current one

            path.push_back(candidates[current_index]); // use the current one
            search(candidates, num, path, current_index+1, ans);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {1,2,3,4};
    int target = 11;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}