#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // easy to think about an algorithm
        // but not easy to have a search method
        map<int,int> begin_count, end_count, overlap_count;
        int previous_count=0, max_count=0;
        for (int i=0;i<points.size();i++){
            if (begin_count.count(points[i][0]) == 0) begin_count[points[i][0]] = 1;
            else begin_count[points[i][0]] += 1;
            if (end_count.count(points[i][1]) == 0) end_count[points[i][1]] = 1;
            else end_count[points[i][1]] += 1;
        }
        int end_pre, begin_now;
        map<int, int>::iterator it=end_count.begin();
        for (auto i:begin_count){
            while (it->first < i.first){
                previous_count -= it->second;
                it++;
            }
            if (begin_count.count(i.first) == 0) begin_now=0;
            else begin_now=begin_count[i.first];
            overlap_count[i.first] = previous_count + begin_now;
            previous_count = overlap_count[i.first];
            if (overlap_count[i.first]>max_count) max_count = overlap_count[i.first];
        }
        return max_count;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        int count = 1;
        int current_end = points[0][1];
        for (int i=1;i<points.size();i++){
            if (points[i][0]<=current_end){
                current_end = current_end < points[i][1] ? current_end:points[i][1];
            }
            else {
                count += 1;
                current_end = points[i][1];
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> in = {{10,16},{2,8},{1,6},{7,12}};
    cout << sol.findMinArrowShots(in) << endl;
    return 0;
}