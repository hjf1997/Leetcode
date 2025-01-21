#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // brutal force version
        // store all coordinates
        set<int> coordinates;
        map<int, int> co2idx, idx2co;
        int n = buildings.size();
        for (int i=0; i<n; i++) { // O(NlogN)
            coordinates.insert(buildings[i][0]); 
            coordinates.insert(buildings[i][1]);
        }
        int temp = 0;
        for (auto c:coordinates){ // O(NlogN)
            idx2co[temp] = c;
            co2idx[c] = temp;
            temp += 1;
        }
        
        vector<int> heights(idx2co.size(), 0);
        for (int i=0; i<n; i++){ // O(N^2)
            int idx_begin = co2idx[buildings[i][0]];
            int idx_end = co2idx[buildings[i][1]];
            for (int j=idx_begin; j<idx_end; j++)
                heights[j] = max(heights[j], buildings[i][2]);
        }

        vector<vector<int>> ans; // O(N)
        ans.push_back({idx2co[0], heights[0]});
        for (int i=1; i<heights.size(); i++){
            if (heights[i] != heights[i-1])
                ans.push_back({idx2co[i], heights[i]});
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> sticks;
        for (int i=0; i<buildings.size(); i++){
            sticks.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            sticks.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        int prev = 0, cur = 0;
        sort(sticks.begin(), sticks.end());
        multiset<int> heights;
        heights.insert(0);
        vector<vector<int>> ans;
        for (auto s: sticks){
            if (s.second < 0){
                heights.insert(-s.second);
            }
            else{
                heights.erase(heights.find(s.second));
            }
            cur = *heights.rbegin();
            if (cur != prev){
                ans.push_back({s.first, cur});
                prev = cur;
            }
        }
        return ans;
    }
};