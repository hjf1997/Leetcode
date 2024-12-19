#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<string> exp;
        int i = 0;
        while (i < expression.size()){
            if (isdigit(expression[i])){
                int j = i;
                while (j < expression.size() && isdigit(expression[j])) j++;
                exp.push_back(expression.substr(i, j-i));
                i = j;
            }
            else{
                exp.push_back(expression.substr(i, 1));
                i++;
            }
        }

        int n = (exp.size() + 1) / 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for (int i=0; i<n; i++){
            dp[i][i] = {stoi(exp[i*2])};
        }
        vector<int> ans = find(exp, dp, 0, n-1);
        return ans;
    }

    vector<int> find(vector<string>& expression, vector<vector<vector<int>>>& dp, int begin, int end){
        if (begin > end) return {};
        if (dp[begin][end].size() > 0) return dp[begin][end];
        else {
            for (int i=begin; i<end; i++){
                vector<int> left = find(expression, dp, begin, i); 
                vector<int> right = find(expression, dp, i+1, end);
                for (auto l: left)
                    for (auto r: right)
                        dp[begin][end].push_back(opt(expression[i+i+1], l, r));
            }
        }
        return dp[begin][end];
    }

    int opt(string op, int l, int r){
        if (op == "+") return l + r;
        else if (op == "-") return l - r;
        else return l * r;
    }
};

int main(){
    Solution sol;
    string expression = "2-1+2";
    vector<int> ans = sol.diffWaysToCompute(expression);
    for (auto a: ans) cout << a << " ";
    cout << endl;
    return 0;
}