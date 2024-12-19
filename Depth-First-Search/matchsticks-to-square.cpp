#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool makesquare(vector<int>& matchsticks) {
//         // Time Limit Exceeded
//         int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//         if (sum % 4 != 0) return false;
//         sum /= 4;
//         vector<int> length(4, sum);
//         int index = 0;
//         bool ans = false;
//         for (int i=0; i<4; i++) search(matchsticks, index, i, length, ans);
//         return ans;
//     }

//     void search(vector<int>& matchsticks, int& index, int& length_index, vector<int>& length, bool& ans){
//         if (index == matchsticks.size()){
//             if (length[0] == 0 && length[1] == 0 && length[2] == 0 && length[3] == 0) ans = true;
//             return;
//         }
//         length[length_index] -= matchsticks[index];
        // if (length[length_index] < 0){
        //     length[length_index] += matchsticks[index];
        //     return;
        // }
//         index += 1;
//         for (int i=0; i<4; i++) search(matchsticks, index, i, length, ans);
//         index -= 1;
//         length[length_index] += matchsticks[index];
//     }
// };

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        sum /= 4;
        vector<int> length(4, sum);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // trigger pruning
        int index = 0;
        bool ans = false;
        for (int i=0; i<4; i++) search(matchsticks, index, i, length, ans);
        return ans;
    }

    void search(vector<int>& matchsticks, int& index, int& length_index, vector<int>& length, bool& ans){
        if (index == matchsticks.size()){
            if (length[0] == 0 && length[1] == 0 && length[2] == 0 && length[3] == 0) ans = true;
            return;
        }
        if (ans) return; // early stopping

        length[length_index] -= matchsticks[index]; // prune
        if (length[length_index] < 0){
            length[length_index] += matchsticks[index];
            return;
        }
        index += 1;
        for (int i=0; i<4; i++) search(matchsticks, index, i, length, ans);
        index -= 1;
        length[length_index] += matchsticks[index];
    }
};

int main(){
    Solution s;
    vector<int> matchsticks = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout << s.makesquare(matchsticks) << endl;
    return 0;
}