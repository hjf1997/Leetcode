#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int ans = -1;
        vector<vector<int>> grid(101+1, vector<int>(101+1, 0));
        for (auto p: points) grid[p[0]+1][p[1]+1] = 1;
        for (int i=1; i<=101; i++)
            for (int j=1; j<=101; j++){
                grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        unordered_set<string> hashmap;
        for (auto p: points) hashmap.insert(l2s(p[0], p[1]));

        for (int i=0; i<points.size(); i++)
            for (int j=0; j<points.size(); j++){
                if (points[j][0] >= points[i][0] || points[j][1] >= points[i][1]) continue;
                if (hashmap.count(l2s(points[i][0], points[j][1])) == 1 &&
                hashmap.count(l2s(points[j][0], points[i][1])) == 1 && 
                grid[points[i][0]+1][points[i][1]+1] + grid[points[j][0]][points[j][1]]
                - grid[points[i][0]+1][points[j][1]] - grid[points[j][0]][points[i][1]+1] == 4){
                    ans = max(ans, (points[i][1] - points[j][1]) * (points[i][0] - points[j][0]));
                }
            }
        return ans;
    }

    string l2s(int x, int y){
        return string(3 - to_string(x).length(), '0') + to_string(x) + string(3 - to_string(y).length(), '0') + to_string(y);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}};
    cout << sol.maxRectangleArea(points) << endl;
    return 0;
}

// class Solution {
// public:
//     int seg_len;
//     vector<int> seg;
//     int maxRectangleArea(vector<vector<int>>& points) {
//         map<int, priority_queue<int>> temp;
//         for (int i=0; i<n; i++){
//             if (map.count(points[i][0]) == 0)
//                 map[points[i][0]] = priority_queue<int>();
//             map[points[i][0]].push(points[i][1]);
//         }

//         // seg tree
//         int n = temp.size();
//         seg_len = 1;
//         while (seg_len < n) seg_len *= 2;
//         seg = vector<int>(seg_len, 200);
//         map<int, int>::iterator it;
//         int c=0;
//         for (it=temp.begin(); it!=temp.end(), it++){
//             init(c, it->second);
//             c += 1;
//         }

//         for ()
//     }

//     void update(int idx){
//         idx += seg_len;
//         seg[idx].pop();
//         for (int i=idx/2; i>=1; i/=2) seg[i] = min(seg[i*2].top(), seg[i*2+1].top());
//     }
    
//     void init(int idx, priority_queue<int> val){
//         idx += seg_len;
//         seg[idx] = val;
//         for (int i=idx/2; i>=1; i/=2) seg[i] = min(seg[i*2].top(), seg[i*2+1].top());
//     }

//     int getMin(int a, int b){
//         a += seg_len;
//         b += seg_len;
//         int ans = seg[a];
//         while (a <= b){
//             if (a%2 == 1){
//                 ans = min(seg[a], ans);
//                 a += 1;
//             }
//             if (b%2 == 0){
//                 ans = min(seg[b], ans);
//                 b -= 1;
//             }
//             a /= 2;
//             b /= 2;
//         }
//     }
// };