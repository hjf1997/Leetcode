#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int lp_count = 0;
        for (int i=0;i<s.size();i++){
            if (s[i] == '*') st.push(s[i]);
            else if (s[i] == '(') {
                st.push(s[i]);
                lp_count += 1;
            }
            else {
                if (st.empty()) return false;
                if (lp_count > 0){
                    int star_count = 0;
                    while (st.top() != '('){
                        st.pop();
                        star_count += 1;
                    }
                    st.pop();
                    lp_count -= 1;
                    while (star_count) {
                        st.push('*');
                        star_count -= 1;
                    }
                }
                else {
                    st.pop();
                }
            }
        }
        int star_count = 0;
        while (!st.empty()){
            if (st.top() == '*') star_count += 1;
            else {
                if (star_count == 0) return false;
                else star_count -= 1;
            }
            st.pop();
        }
        return true;
    }
};


int main(){
    Solution sol;
    string s = "(((****";
    cout << sol.checkValidString(s) << endl;
    return 0;
}