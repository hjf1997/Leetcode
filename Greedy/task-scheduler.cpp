#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int max_freq=0, max_count=0;
        for (int i=0;i<tasks.size();i++){
            count[tasks[i]-'A'] += 1;
            if (count[tasks[i]-'A']>max_freq) {max_freq = count[tasks[i]-'A']; max_count=1;}
            else if (count[tasks[i]-'A']==max_freq) max_count+=1;
        }
        int num_interval = max_freq - 1;
        int num_max_idle = num_interval * n - num_interval * (max_count - 1);
        int num_rest_tasks = tasks.size() - max_freq * max_count;
        int num_idle = max(0, num_max_idle-num_rest_tasks);
        return tasks.size() + num_idle;
    }
};

int main(){
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B','C','C','C','D','E'};
    int n = 2;
    cout<<sol.leastInterval(tasks, n) << endl;
}