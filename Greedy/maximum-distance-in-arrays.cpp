#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left = arrays[0][0], right = arrays[0].back();
        int res = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, abs(arrays[i].back() - left));
            res = max(res, abs(right - arrays[i][0]));
            left = min(left, arrays[i][0]);
            right = max(right, arrays[i].back());
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> in = {{1},{1}};
    cout << sol.maxDistance(in) << endl;
}