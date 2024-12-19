#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        ans = search(m, n, maxMove, startRow, startColumn, dp);
        return ans;
    }

    int search(int m, int n, int maxMove, int currentRow, int currentColum, vector<vector<vector<int>>>& dp){
        if (maxMove < 0) return 0;
        if (currentRow == m || currentRow == -1 || currentColum == -1 || currentColum == n) return 1;
        if (dp[currentRow][currentColum][maxMove] != -1) return dp[currentRow][currentColum][maxMove];
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        for (auto& dir : directions){
            int newRow = currentRow + dir[0];
            int newColum = currentColum + dir[1];
            count = modulo(count, search(m, n, maxMove-1, newRow, newColum, dp));
        }
        dp[currentRow][currentColum][maxMove] = count;
        return dp[currentRow][currentColum][maxMove];
    }

    int modulo(int a, int b){
        int cont = 1e9+7;
        return (a%cont + b%cont)%cont;
    }
};

int main(){
    Solution sol;
    cout << sol.findPaths(2, 2, 2, 0, 0) << endl;
    return 0;
}