#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k==num.size()) return "0";
        stack<char> st;
        const int p=num.size()-k;
        int num_left=num.size(), index=0;
        while (index<num.size()){
            if (st.empty()) {
                st.push(num[index]);
                index += 1;
                num_left -= 1;
                continue;
            } 
            while (!st.empty() && st.size() + num_left > p && st.top() > num[index]) st.pop();
            if (st.size() < p) st.push(num[index]);
            num_left -= 1;
            index += 1;
        }
        string ans;
        while (!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
        reverse(ans.begin(),ans.end());
        while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "";
    int k =50000;
    cout << sol.removeKdigits(s, k) << endl;
}

