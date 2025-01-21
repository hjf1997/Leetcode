#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     struct BIT{
//         int length;
//         vector<int> tree, coordinate;
//         BIT(int l): length(l) {
//             tree = vector<int>(length+1);
//             coordinate = vector<int>(length);
//         }

//         void update(){

//         }

        
//     }

//     vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
//         sort(rectangles.begin(), rectangles.end(), [](vector<int>a, vector<int>b){
//             return a[0] > b[0];
//         })

//     }

    
// };

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = rectangles.size(), m = points.size();
        sort(rectangles.begin(), rectangles.end(), [](vector<int>a, vector<int>b){
            return a[0] > b[0];
        }); // O(NLogN)
        vector<vector<int>> temp_points(m, vector<int>(3));
        for (int i=0; i<m; i++){
            temp_points[i][0] = points[i][0];
            temp_points[i][1] = points[i][1];
            temp_points[i][2] = i;
        }
        sort(temp_points.begin(), temp_points.end(), [](vector<int>a, vector<int>b){
            return a[0] > b[0];
        }); // O(MLogM)
        vector<int> y_count(101, 0), ans(m, 0);
        
        // O(100M)
        int x_index = 0;
        for (int i=0; i<m; i++){
            while (x_index < n && rectangles[x_index][0] >= temp_points[i][0]){
                y_count[rectangles[x_index][1]] += 1;
                x_index += 1;
            }
            // this part can be replaced by a BIT but it is not necessary as the time complexity is O(100)
            ans[temp_points[i][2]] = accumulate(y_count.begin() + temp_points[i][1], y_count.end(), 0);
        }
        return ans;


    }
};

int main(){
    Solution sol;
    vector<vector<int>> rectangles = {{1,1}, {2,2}, {3,3}};
    vector<vector<int>> points = {{1,3},{1,1}};
    vector<int> ans = sol.countRectangles(rectangles, points);
    for (auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}