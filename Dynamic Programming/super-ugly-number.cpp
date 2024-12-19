#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> dp;
        dp.push(1);
        int current, count=0;
        while (count < n){
            current = dp.top();
            dp.pop();
            count += 1;
            while (!dp.empty() && current == dp.top()) dp.pop();
            for (auto p: primes){
                if (p <= INT_MAX / current) dp.push(current * p);
            }
        }
        return current;
    }
};

int main(){
    Solution sol;
    vector<int> primes = {2, 3, 5};
    int n = 1;
    cout << sol.nthSuperUglyNumber(n, primes) << endl;
    return 0;
}