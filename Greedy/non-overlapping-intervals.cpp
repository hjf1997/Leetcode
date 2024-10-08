#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int current=0, count=1;
        for (int i=1;i<intervals.size();i++){
            if (intervals[i][0]<intervals[current][1]) continue;
            current=i;
            count+=1;
        }
        return intervals.size() - count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> in = {{1,2}};
    cout << sol.eraseOverlapIntervals(in) << endl;
    return 0;
}
