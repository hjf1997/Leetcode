#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<char> max_num(s.size());
        max_num[max_num.size()-1] = s.back();
        for (int i=max_num.size()-2;i>=0;i--){
            max_num[i] = s[i] > max_num[i+1] ? s[i] : max_num[i+1];
        }
        int left=-1, right=-1;
        char target;
        for (int i=0;i<s.size()-1;i++){
            if (s[i] < max_num[i+1]){
                left = i;
                target = max_num[i+1];
                break;
            }
        }
        if (left == -1) return num;
        for (int i=s.size()-1;i>=0;i--){
            if (s[i] == target) {right = i; break;}
        }
        swap(s[left], s[right]);
        int ans = stoi(s);
        return ans;
    }
};

int main(){
    Solution sol;
    int num=12;
    cout << sol.maximumSwap(num) << endl;
    return 0;
}