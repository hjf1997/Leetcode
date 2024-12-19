#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open_num = n, close_num = n, unclosed_num = 0;
        string candidate = "";
        vector<string> ans;
        search(ans, candidate, open_num, close_num, unclosed_num);
        return ans;
    }

    void search(vector<string>& ans, string& candidate, int& open_num, int& close_num, int& unclosed_num){
        if (open_num == 0 && close_num == 0){
            ans.push_back(candidate);
            return;
        }
        if (open_num){
            open_num -= 1;
            unclosed_num += 1;
            candidate += '(';
            search(ans, candidate, open_num, close_num, unclosed_num);
            open_num += 1;
            unclosed_num -= 1;
            candidate.pop_back();
        }
        if (close_num){
            if (unclosed_num - 1 < 0) return;
            close_num -= 1;
            unclosed_num -= 1;
            candidate += ')';
            search(ans, candidate, open_num, close_num, unclosed_num);
            close_num += 1;
            unclosed_num += 1;
            candidate.pop_back();
        }
    }
};

int main(){
    Solution sol;
    int n = 4;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto s: ans) cout << s << endl;
    return 0;
}