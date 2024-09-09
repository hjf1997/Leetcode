#include <iostream>
#include <algorithm> // Include the <algorithm> header for lower_bound
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    struct Pair{
        int key;
        int value;
        bool operator < (const Pair &p) const{
            return value < p.value;
        }
        int operator + (const Pair &p) const{
            return value + p.value;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<Pair> p;
        for (int i = 0; i < nums.size(); i++){
            Pair temp;
            temp.key = i;
            temp.value = nums[i];
            p.push_back(temp);
        }
        sort(p.begin(), p.end());

        int left = 0, right = nums.size()-1;
        while (left < right){
            int sum = p[left] + p[right];
            if (sum < target){
                left += 1;
            } else if (sum > target){
                right -= 1;
            } else{
                ans = {p[left].key, p[right].key};
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> ans = sol.twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}