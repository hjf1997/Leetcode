#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct BIT{
        int n;
        vector<int> tree;
        BIT(int _n): n(_n), tree(vector<int>(n, 0)){}

        void update(int idx, int val){
            for (int i=idx; i<n; i+=(i&-i)) tree[i] += val;
        }

        int getSum(int idx){
            int s = 0;
            for (int i=idx; i>0; i-=(i&-i)) s += tree[i];
            return s;
        }
    };

    struct triple{
        double num;
        int idx;
        bool half;

        triple(double _num, int _idx, bool _half): num(_num), idx(_idx), half(_half) {}
        triple(): num(0.), idx(0), half(false) {}
    };

    int reversePairs(vector<int>& nums) {
        // this code should use doulbe precision
        int n = nums.size(), count = 0;
        vector<double> half_nums(n);
        BIT bit(2 * n + 1);
        for (int i=0; i<n; i++) half_nums[i] = static_cast<double>(nums[i]) / 2;
        vector<triple> whole_nums(2 * nums.size());
        for (int i=0; i<n; i++) whole_nums[i] = triple(half_nums[i], i, true);
        for (int i=n; i<2*n; i++) whole_nums[i] = triple(static_cast<double>(nums[i-n]), i, false);

        sort(whole_nums.begin(), whole_nums.end(), [](triple a, triple b){
            return a.num != b.num ? a.num > b.num : a.idx > b.idx;
        });
        vector<int> sorted_idx(n), sorted_half_idx(n);
        for (int j=0; j<2*n; j++){
            if (whole_nums[j].half == true) sorted_half_idx[whole_nums[j].idx] = j;
            else sorted_idx[whole_nums[j].idx - n] = j;
        }

        for (int i=0; i<n; i++){
            count += bit.getSum(sorted_idx[i]); // no need to add 1
            bit.update(sorted_half_idx[i] + 1, 1);
        }

        return count;
    }
};

class Solution {
public:

    struct BIT{
        int n;
        vector<int> tree;

        BIT(int _n): n(_n), tree(vector<int>(n)){}

        void update(int idx, int val){
            for (int i=idx; i>0; i-=(i&-i)) tree[i] += val;
        }

        int getSum(int idx){
            int s = 0;
            for (int i=idx; i<n; i+=(i&-i)) s += tree[i];
            return s;
        }
    };

    int reversePairs(vector<int>& nums) {
        // Simplified BIT version
        int n = nums.size(), count = 0;
        vector<long long> sorted_nums(nums.begin(), nums.end());
        sort(sorted_nums.begin(), sorted_nums.end());
        BIT bit(n + 1);

        for (int i=0; i<n; i++){
            int idx = upper_bound(sorted_nums.begin(), sorted_nums.end(), static_cast<long long>(2)*nums[i]) - sorted_nums.begin();
            count += bit.getSum(idx+1);

            int idx2 = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            bit.update(idx2+1, 1);
        }

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,1};
    cout << sol.reversePairs(nums) << endl;
    return 0;
}