#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 0;
        priority_queue<int, vector<int>, greater<int>> num;
        num.push(1);
        int current_num = 1;
        while (count < n){
            current_num = num.top();
            num.pop();
            if (!num.empty() && current_num == num.top()) continue;
            if (current_num <= INT_MAX / 2) num.push(current_num * 2);
            if (current_num <= INT_MAX / 3) num.push(current_num * 3);
            if (current_num <= INT_MAX / 5) num.push(current_num * 5);
            count += 1;
        }
        return current_num;
    }
};

int main(){
    Solution sol;
    int n = 18;
    cout << sol.nthUglyNumber(n) << endl;
    return 0;
}