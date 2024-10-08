#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::comp);
        string ans;
        for (auto i:nums){
            ans += to_string(i);
        }
        if (ans[0] == '0') ans = "0";
        return ans; // pay attention whether the string ans is a valid number, like 00
    }

    static bool comp(int num1, int num2){
        string num1_str = to_string(num1);
        string num2_str = to_string(num2);
        int length = min(num1_str.size(), num2_str.size());
        for (int i=0; i<length; i++){
            if (num1_str[i] > num2_str[i]) return true;
            if (num1_str[i] < num2_str[i]) return false;
        }
        string cand1=num1_str+num2_str, cand2=num2_str+num1_str;
        return cand1 > cand2 ? true:false;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {0,0};
    cout << sol.largestNumber(nums) << endl;
    return 0;
}