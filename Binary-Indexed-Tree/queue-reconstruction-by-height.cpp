#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int n;

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        bit = vector<int>(n+1, 0);
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for (int i=2; i<bit.size(); i++) update(i, 1);
        vector<vector<int>> ans(n, vector<int>());

        for (const auto& person : people){
            int v = person[0], k = person[1];
            int l=1, r=n;
            while (l < r){
                int mid = (l + r) / 2;
                if (getSum(mid) >= k) r = mid;
                else l = mid + 1;
            }
            ans[l-1] = {v, k};
            update(l, -1);
        }
        return ans;
    }

    void update(int index, int val){
        for (int i=index; i<=n; i+=(i&-i)){
            bit[i] += val;
        }
    }

    int getSum(int index){
        int sum = 0;
        for (int i=index; i>0; i-=(i&-i)){
            sum += bit[i];
        }
        return sum;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> ans = sol.reconstructQueue(people);
    for (const auto& a : ans){
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}