#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(n, vector<int>());
        for (int i=0; i<n; i++)
            for (int j=1; j<=n; j++){
                if ((i+1) % j == 0 || j % (i+1) == 0) dp[i].push_back(j);
            }
        int ans=0, index=0;
        vector<bool> visit(n, false);
        search(n, dp, visit, ans, index);
        return ans;
    }

    void search(int n, vector<vector<int>>& dp, vector<bool>& visit, int& ans, int index){
        if (index == n){
            ans += 1;
            return;
            }
        if (dp[index].empty()) return;
        for (int i=0; i<dp[index].size(); i++){
            if (visit[dp[index][i]-1] == false){
                visit[dp[index][i]-1] = true;
                search(n, dp, visit, ans, index+1);
                visit[dp[index][i]-1] = false;
            }
        }
    }
};

int main(){
    Solution sol;
    cout << sol.countArrangement(4) << endl;
    return 0;
}