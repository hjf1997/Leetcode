#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    vector<int> BIT;
    vector<int> countSmaller(vector<int>& nums) {
        // binary indexed tree version
        reverse(nums.begin(), nums.end());
        n = nums.size();
        BIT = vector<int>(n+1, 0);
        vector<pair<int,int>> temp(n);
        vector<int> idxes(n);
        for (int i=0; i<n; i++) temp[i] = make_pair(nums[i], i);
        sort(temp.begin(), temp.end(), [](pair<int,int>a, pair<int,int>b){
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });
        for (int j=0; j<n; j++) idxes[temp[j].second] = j;

        vector<int> ans(n);
        for (int i=0; i<n; i++){
            int idx = idxes[i];
            ans[i] = getSum(idx+1);
            update(idx+1, 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void update(int idx, int val){
        for (int i=idx; i<=n; i+=(i&-i)) BIT[i] += val;
    }

    int getSum(int idx){
        int ans = 0;
        for (int i=idx; i>0; i-=(i&-i)) ans += BIT[i];
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,2,6,1};
    vector<int> ans = sol.countSmaller(nums);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}