#include <bits/stdc++.h>
using namespace std;

class Solution {
    // This is a task scheduling problem
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});
        int pre_end=pairs[0][1], count=1;
        for (int i=1;i<pairs.size();i++){
            if (pre_end >= pairs[i][0]) continue;
            pre_end = pairs[i][1];
            count += 1;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> pairs = {{1, 3}, {2,4}, {4,6}, {6,7}, {100,101}};
    cout << sol.findLongestChain(pairs) << endl;
    return 0;
}
