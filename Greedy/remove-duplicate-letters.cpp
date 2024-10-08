#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        // how to put index char in vector
        vector<int> last_index(26, 0);
        vector<bool> visited(26, false);
        stack<char> st;
        for (int i=0; i<s.size(); i++) last_index[s[i]-'a'] = i;
        for (int i=0; i<s.size(); i++){
            if (st.empty()) {
                st.push(s[i]);
                visited[s[i]-'a'] = true;
                continue;
            }
            if (visited[s[i]-'a']) continue;
            while (!st.empty() && st.top() > s[i] && last_index[st.top()-'a'] > i){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        while(!st.empty()){
          ans=st.top() + ans;
          st.pop();
      }
      return ans;
    }
};

int main(){
    Solution sol;
    string s = "abacb";
    cout << sol.removeDuplicateLetters(s) << endl;
}