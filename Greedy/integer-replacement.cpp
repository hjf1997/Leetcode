#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long long N = static_cast<long long>(n);
        int count = 0;
        while (N!=1){
            N = next_number(N);
            count += 1;
        }
        return count;
    }

    long long next_number(long long n){
        if (n % 2 == 0) return n/2;
        if (n==3) return n-1;
        if ((n+1)/2%2==0 && (n-1)/2%2==0) return n-1;
        else if ((n+1)/2%2==0) return n+1;
        else return n-1;
    }
};


int main(){
    Solution sol;
    int n = 10000;
    cout << sol.integerReplacement(n) << endl;
    return 0;
}