#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = 0;
        while (left < right){
            int wall = min(height[left], height[right]);
            int area = wall * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right]){
                left += 1;
            } else{
                right -= 1;
            }
        }
        return max_area;
    }
};