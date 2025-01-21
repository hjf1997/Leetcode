#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct BIT{
        vector<int> tree;
        int n;

        BIT(int _n): n(_n), tree(vector<int>(_n, 0)) {
            for (int i=1; i<n; i++) update(i, 1);
        }

        void update(int idx, int val){
            for (int i=idx; i<n; i+=(i&-i)) tree[i] += val;
        }

        int getSum(int l, int r){
            int l_sum = 0, r_sum = 0;
            l -= 1;
            for (int i=l; i>0; i-=(i&-i)) l_sum += tree[i];
            for (int i=r; i>0; i-=(i&-i)) r_sum += tree[i];
            return r_sum - l_sum;
        }
    };

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // Binary Indexed Tree version
        int ans = 0, n = nums.size();
        BIT bit(n+2);

        vector<long long> sum(n+1, 0);
        for (int i=1; i<=n; i++) sum[i] = sum[i-1] + nums[i-1];
        vector<long long> sorted_sum(sum.begin(), sum.end());
        sort(sorted_sum.begin(), sorted_sum.end());
        for (const auto& s: sum){
            int s_idx = lower_bound(sorted_sum.begin(), sorted_sum.end(), s) - sorted_sum.begin();
            int lower_idx = lower_bound(sorted_sum.begin(), sorted_sum.end(), s+lower) - sorted_sum.begin();
            int upper_idx = upper_bound(sorted_sum.begin(), sorted_sum.end(), s+upper) - 1 - sorted_sum.begin();
            bit.update(s_idx+1, -1);
            ans += bit.getSum(lower_idx+1, upper_idx+1);
        }
        return ans;
    }

};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // merge sort version
        int n = nums.size(), l = 0, r = n + 1;
        vector<long long> sums(n+1, 0);
        for (int i=1; i<sums.size(); i++) sums[i] = sums[i-1] + nums[i-1];
        int count = countWhileMergeSort(sums, l, r, lower, upper);
        return count;
    }

    int countWhileMergeSort(vector<long long>& sums, int l, int r, int lower, int upper){
        if (r - l <= 1) return 0;

        int mid = (r + l) / 2;
        int count = countWhileMergeSort(sums, l, mid, lower, upper) +
                        countWhileMergeSort(sums, mid, r, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long long> temp(r-l, 0);
        for (int i=l, sort_idx=0; i<mid; i++, sort_idx++){
            while (j < r && sums[j] - sums[i] < lower) j += 1; // find lower bond
            while (k < r && sums[k] - sums[i] <= upper) k += 1; // find upper bond
            while (t < r && sums[t] < sums[i]){
                temp[sort_idx] = sums[t];
                t += 1;
                sort_idx += 1;
            }
            temp[sort_idx] = sums[i];
            count += k - j;
        }
        copy(temp.begin(), temp.begin() + t - l, sums.begin() + l);
        return count;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // merge sort version, end inclusive 
        int n = nums.size(), l = 0, r = n;
        vector<long long> sums(n+1, 0);
        for (int i=1; i<sums.size(); i++) sums[i] = sums[i-1] + nums[i-1];
        int count = countWhileMergeSort(sums, l, r, lower, upper);
        return count;
    }

    int countWhileMergeSort(vector<long long>& sums, int l, int r, int lower, int upper){
        // this version is end inclusive
        if (r - l == 0) return 0;

        int mid = (r + l) / 2;
        int count = countWhileMergeSort(sums, l, mid, lower, upper) +
                        countWhileMergeSort(sums, mid+1, r, lower, upper);
        int j = mid+1, k = mid+1, t = mid+1;
        vector<long long> temp(r-l+1, 0);
        for (int i=l, sort_idx=0; i<=mid; i++, sort_idx++){
            while (j <= r && sums[j] - sums[i] < lower) j += 1; // find lower bond
            while (k <= r && sums[k] - sums[i] <= upper) k += 1; // find upper bond
            while (t <= r && sums[t] < sums[i]){
                temp[sort_idx] = sums[t];
                t += 1;
                sort_idx += 1;
            }
            temp[sort_idx] = sums[i];
            count += k - j;
        }
        copy(temp.begin(), temp.begin() + t - l, sums.begin() + l);
        return count;
    }
};