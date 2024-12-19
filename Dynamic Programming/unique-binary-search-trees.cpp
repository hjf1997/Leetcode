#include <bits/stdc++.h>
using namespace std;

// brutal force
// class Solution {
// public:
//     int numTrees(int n) {
//         return countTrees(0, n-1);
//     }

//     int countTrees(int start, int end){
//         if (start > end) return 1;
//         int count = 0;
//         for (int i=start; i<=end; i++){
//             count += countTrees(start, i-1) * countTrees(i+1, end);
//         }
//         return count;
//     }
// };

// dynamic programming
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        return countTrees(0, n-1, dp);
    }

    int countTrees(int start, int end, vector<int>& dp){
        if (start > end) return 1;
        if (dp[end - start + 1] != 0) return dp[end - start + 1];
        int count = 0;
        for (int i=start; i<=end; i++){
            count += countTrees(start, i-1, dp) * countTrees(i+1, end, dp);
        }
        dp[end - start + 1] = count;
        return count;
    }
};

int main(){
    Solution sol;
    int count = sol.numTrees(19);
    // print trees
    cout << count << endl;
    return 0;
}