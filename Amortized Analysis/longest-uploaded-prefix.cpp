#include <bits/stdc++.h>
using namespace std;

class LUPrefix {
public:
    vector<bool> q;
    int min_null_index;
    LUPrefix(int n) {
        q = vector<bool>(n+1, false);
        min_null_index = 1;
    }
    
    void upload(int video) {
        // can use a segment tree to obtain and maintain the min value
        q[video] = true;
        if (min_null_index == video){
            while (min_null_index < q.size() && q[min_null_index]) {
                min_null_index++;
            }
        }
    }
    
    int longest() {
        return min_null_index - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */