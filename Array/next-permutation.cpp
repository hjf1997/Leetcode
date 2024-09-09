#include <bits/stdc++.h>
using namespace std;
// O(n*logn) time complexity
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         if (nums.size() == 1) return;
//         int high_index = -1;
//         for (int i = 1; i < nums.size(); i++){
//             if (nums[i] > nums[i-1]) high_index = i;
//         }
//         if (high_index == -1){
//             sort(nums.begin(), nums.end());
//             return;
//         }
//         sort(nums.begin() + high_index, nums.end());
//         for (int i = high_index; i < nums.size(); i++){
//             if (nums[i] > nums[high_index-1]){
//                 swap(nums[i], nums[high_index-1]);
//                 break;
//             }
//         }
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int high_index = -1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]) high_index = i;
        }
        if (high_index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + high_index, nums.end());
        for (int i = high_index; i < nums.size(); i++){
            if (nums[i] > nums[high_index-1]){
                swap(nums[i], nums[high_index-1]);
                break;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 5};
    // factorial i 
    for (int i = 0; i < accumulate(nums.begin(), nums.end(), 1, multiplies<int>()); i++){
        sol.nextPermutation(nums);
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


// [1, 2, 3, 4]
// [1, 2, 4, 3]
// [1, 3, 2, 4]

// [1, 2, 3, 4, 5]
// [1, 2, 3, 5, 4]
// [1, 2, 4, 3, 5]
// [1, 2, 4, 5, 3] //
// [1, 2, 5, 3, 4]
// [1, 2, 5, 4, 3] //
// [1, 3, 2, 4, 5]
// [1, 3, 2, 5, 4]
// [1, 3, 4, 2, 5]
// [1, 3, 4, 5, 2]
// [1, 3, 5, 2, 4]
// [1, 3, 5, 4, 2]
// [1, 4, 2, 3, 5]
// [1, 4, 2, 5, 3]
// [1, 4, 3, 2, 5]
// [1, 4, 3, 5, 2]
// [1, 4, 5, 2, 3]
// [1, 4, 5, 3, 2]
// [1, 5, 2, 3, 4]