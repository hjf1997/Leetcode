#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        auto cmp = [](pair<int, int> a, pair<int,int> b){
            if (a.first == b.first) return a.second > b.second;
            else return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> qe(cmp);
        int i = 0;
        while (i < nums.size()){
            if (qe.empty()) {qe.push({nums[i],1}); i+=1; continue;}
            pair<int, int> tmp = qe.top();
            if (nums[i] == tmp.first) {qe.push({nums[i], 1}); i+=1;}
            else if (nums[i] == tmp.first + 1) {
                qe.pop();
                qe.push({tmp.first+1, tmp.second+1});
                i += 1;
            }
            else {
                if (tmp.second < 3) return false;
                qe.pop();
            }
        }
        while (!qe.empty()){
            if (qe.top().second < 3) return false;
            qe.pop();
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,3,3,4,5};
    cout << sol.isPossible(nums) << endl;
    return 0;
}