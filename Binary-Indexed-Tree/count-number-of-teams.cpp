#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        // O(N^2) version
        vector<int> dp_small(rating.size(), 0);
        vector<int> dp_large(rating.size(), 0);
        int n = rating.size();
        int ans = 0;
        for (int i=1; i<n; i++)
            for (int j=0; j<i; j++){
                if (rating[j] < rating[i]) dp_small[i] += 1;
                if (rating[j] > rating[i]) dp_large[i] += 1;
            }
        for (int i=2; i<n; i++)
            for (int j=1; j<i; j++){
                if (rating[j] < rating[i]) ans += dp_small[j];
                if (rating[j] > rating[i]) ans += dp_large[j];
            }
        return ans;
    }
};

class Solution {
public:
    vector<pair<int, int>> BIT;
    int n;

    int numTeams(vector<int>& rating) {
        // O(NLogN) version
        // We can use binary indexed tree for this problem, as we need to get sum
        n = rating.size();
        int ans = 0;

        // how many preceding numbers are smaller than the current
        // whether current is visited
        BIT = vector<pair<int, int>>(n + 1, {0, 0}); // NOTE: BIT index should be one-indexed;
        // check increasing sequence
        vector<pair<int, int>> temp(n);
        for (int i=0; i<n; i++) temp[i] = {rating[i], i}; // num, index
        sort(temp.begin(), temp.end());
        vector<int> sorted_index(n);
        for (int i=0; i<n; i++) sorted_index[temp[i].second] = i;

        update(sorted_index[0]+1, 0);
        for (int i=1; i<n; i++){
            ans += getSum(sorted_index[i] + 1, true);
            update(sorted_index[i] + 1, getSum(sorted_index[i] + 1, false));
        }

        // check decreasing sequence
        BIT = vector<pair<int, int>>(n + 1, {0, 0});
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        for (int i=0; i<n; i++) sorted_index[temp[i].second] = i;
        update(sorted_index[0]+1, 0);
        for (int i=1; i<n; i++){
            ans += getSum(sorted_index[i] + 1, true);
            update(sorted_index[i] + 1, getSum(sorted_index[i] + 1, false));
        }

        return ans;
    }

    void update(int idx, int val){
        // idx is the index for BIT, NOT rating
        // int delta = val - BIT[idx].first;
        // NEVER use delta, this assumes the sum range is 1 only at a leaf node, which is not always true
        for (int i=idx; i<=n; i+=(i&-i)) {
            BIT[i].first += val;
            BIT[i].second += 1;
        }
    }

    int getSum(int idx, bool count_path){
        // a and b are the inexes for BIT, NOT rating
        int s = 0;
        for (int i=idx; i>=1; i-=(i&-i)){
            if (count_path) s += BIT[i].first;
            else s += BIT[i].second;
        }
        return s;
    }
};