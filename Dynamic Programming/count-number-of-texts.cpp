#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int countTexts(string pressedKeys) {
    //     // (a + b) mod m = (a mod m + b mod m) mod m
    //     vector<int> dp(pressedKeys.length()+1);
    //     dp[0] = 1, dp[1] = 1; // base case
    //     for (int i=2; i<=pressedKeys.length(); i++){ // use dp array index
    //         dp[i] = dp[i-1];
    //         if (pressedKeys[i-1] == pressedKeys[i-2]) {
    //             dp[i] = modulo_add(dp[i], dp[i-2]);
    //             if (i >= 3 && pressedKeys[i-1] == pressedKeys[i-3]) {
    //                 dp[i] = modulo_add(dp[i], dp[i-3]);
    //                 // special case 9
    //                 if (i >= 4 && pressedKeys[i-1] == pressedKeys[i-4] && (pressedKeys[i-1] == '9' || pressedKeys[i-1] == '7')) dp[i] = modulo_add(dp[i], dp[i-4]);
    //             }
                 
    //         }
    //     }
    //     return dp.back();
    // }

    int countTexts(string pressedKeys) {
        // (a + b) mod m = (a mod m + b mod m) mod m
        vector<int> dp(pressedKeys.length()+1);
        dp[0] = 1, dp[1] = 1; // base case
        for (int i=1; i<pressedKeys.length(); i++){ // use pressdKeys array index
            // I think this way is easier to understand !!!
            dp[i+1] = dp[i];
            if (pressedKeys[i] == pressedKeys[i-1]) {
                dp[i+1] = modulo_add(dp[i+1], dp[i-1]);
                if (i >= 2 && pressedKeys[i] == pressedKeys[i-2]) {
                    dp[i+1] = modulo_add(dp[i+1], dp[i-2]);
                    // special case 9
                    if (i >= 3 && pressedKeys[i] == pressedKeys[i-3] && (pressedKeys[i] == '9' || pressedKeys[i] == '7')) dp[i+1] = modulo_add(dp[i+1], dp[i-3]);
                }
                 
            }
        }
        return dp.back();
    }

    int modulo_add(int a, int b){
        int mod = 1e9 + 7;
        return (a % mod + b % mod) % mod;
    }
};

int main(){
    Solution sol;
    string word1 = "55555555999977779555";
    cout << sol.countTexts(word1) << endl;
    return 0;
}