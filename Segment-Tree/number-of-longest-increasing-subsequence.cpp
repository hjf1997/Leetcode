#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         // O(N^2) version
//         vector<int> dp(nums.size(), 1), max_nums(nums.size(), 1);
//         int max_length = 1;
//         for (int i=0; i<dp.size(); i++)
//             for (int j=0; j<i; j++){
//                 if (nums[j] < nums[i]){
//                     if (dp[j]+1 > dp[i]){
//                         max_nums[i] = max_nums[j];
//                         dp[i] = dp[j]+1;
//                     }
//                     else if (dp[j]+1 == dp[i])
//                         max_nums[i] += max_nums[j];
//                 }
//             max_length = max(max_length, dp[i]);
//             }
        
//         int ans = 0;
//         for (int i=0; i<nums.size(); i++){
//             if (dp[i] == max_length) ans += max_nums[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int n, seg_length;
    vector<pair<int, int>> seg;

    int findNumberOfLIS(vector<int>& nums) {
        // O(NlogN) Version
        // Seems we need to use segment tree instead of binary indexed tree
        // Yes this is correct
        n = nums.size();
        seg_length = 1; // to a length of power of 2;
        while (seg_length < n) seg_length *= 2;
        seg = vector<pair<int, int>>(seg_length * 2, {0, 0});  // max / sum segment tree (equivalent to dp)
        vector<int> sorted_index(n);

        // sorting
        vector<pair<int, int>> temp_nums(nums.size());
        for (int i=0; i<n; i++) temp_nums[i] = {nums[i], i}; // number, index
        sort(temp_nums.begin(), temp_nums.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        }); // must strictly increasing
        for (int i=0; i<n; i++) sorted_index[temp_nums[i].second] = i;
        
        // update the dp seg_tree
        update(sorted_index[0], 1, 1);
        for (int i=1; i<n; i++){
            pair<int, int> p = getMax(0, sorted_index[i] - 1);
            update(sorted_index[i], p.first + 1, p.second);
        }
        return seg[1].second;
    }

    void update(int index, int len, int num){
        index += seg_length;
        seg[index] = {len, num};
        for (index/=2; index>0; index/=2){
            if (seg[index * 2].first == seg[index * 2 + 1].first){
                seg[index].first = seg[index * 2].first; // redundant
                seg[index].second = seg[index * 2].second + seg[index * 2 + 1].second;
            } else{
                seg[index].first = max(seg[index * 2].first, seg[index * 2 + 1].first);
                seg[index].second = seg[index].first == seg[index * 2].first
                ? seg[index * 2].second : seg[index * 2 + 1].second;
            }
        }
    }

    pair<int, int> getMax(int a, int b){
        a += seg_length, b += seg_length;
        pair<int, int> s = {0, 0};
        while (a <= b){
            if (a%2 == 1){
                if (seg[a].first > s.first) s = {seg[a].first, seg[a].second};
                else if (seg[a].first == s.first) s.second += seg[a].second;
                a += 1;
            } 
            if (b%2 == 0){
                if (seg[b].first > s.first) s = {seg[b].first, seg[b].second};
                else if (seg[b].first == s.first) s.second += seg[b].second;
                b -= 1;
            }
            a /= 2, b /= 2;
        }
        // speical case
        if (s.second == 0) s.second = 1;
        return s;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,5,4,7};
    cout << sol.findNumberOfLIS(nums) << endl;
    return 0;
}