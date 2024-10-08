#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<bool> dq(senate.size(), false);
        queue<char> vote;
        map<char, int> dq_count, senate_count;
        dq_count['R'] = 0;
        dq_count['D'] = 0;
        senate_count['R'] = 0;
        senate_count['D'] = 0;
        for (int i=0;i<senate.size();i++) {
            vote.push(senate[i]);
            senate_count[senate[i]] += 1;
        }
        while (senate_count['R'] && senate_count['D']){
            char current = vote.front();
            vote.pop();
            if (dq_count[current] > 0){
                dq_count[current] -= 1;
                senate_count[current] -= 1;
            } else{
                dq_count[current == 'R' ? 'D' : 'R'] += 1;
                vote.push(current);
            }
        }
        if (senate_count['R']) return "Radiant";
        else return "Dire";
    }
};

int main(){
    Solution sol;
    string senate = "RDRRDRD";
    cout << sol.predictPartyVictory(senate) << endl;
    return 0;
}