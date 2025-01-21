#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<vector<int>> ans(n, vector<int>(n, -1));
        return search(height, ans, 0, n - 1);
    }

    int search(vector<int>& height, vector<vector<int>>& ans, int left, int right){
        if (right - left <= 1){
            ans[left][right] = 0;
            return 0;
        }

        if (ans[left][right] != -1) return ans[left][right];

        if (right - left == 2){
            ans[left][right] = max(0, min(height[left], height[right]) - height[left + 1]);
        } else {
            int middle_wall = 0, min_wall = min(height[left], height[right]);
            for (int mid=left+1; mid<=right-1; mid++){
                int cand = search(height, ans, left, mid) + search(height, ans, mid, right);
                ans[left][right] = max(ans[left][right], cand);
                middle_wall += min(min_wall, height[mid]);
            }
            ans[left][right] = max(ans[left][right], min_wall * (right - left - 1) - middle_wall);
        }
        return ans[left][right];
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        // stack version
        stack<pair<int, int>> st;
        int n = height.size(), ans = 0;
        st.push(make_pair(height[0], 0));

        int current_stack_max = height[0];
        for (int i=1; i<n; i++){
            if (current_stack_max <= height[i]){
                while (st.top().first != current_stack_max) st.pop();
                st.push(make_pair(height[i], i));
                current_stack_max = height[i];
            } else{
                while (st.top().first < height[i]) st.pop();
                st.push(make_pair(height[i], i));
            }
        }

        // calculate water, the above algorithm can guarantee min 2 elements
        pair<int, int> right_wall = st.top();
        st.pop();
        while (!st.empty()){
            pair<int, int> left_wall = st.top();
            int middle_height = 0;
            st.pop();
            for (int i=left_wall.second+1; i<=right_wall.second-1; i++) middle_height += height[i];
            ans += (right_wall.second - left_wall.second - 1) * min(left_wall.first, right_wall.first) - middle_height;
            right_wall = left_wall;
        }
        return ans;
    }
};