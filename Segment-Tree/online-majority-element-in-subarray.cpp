#include <bits/stdc++.h>
using namespace std;

class MajorityChecker {
public:

    int getOccurrence(int val, int l, int r){
        auto index_l = lower_bound(pos[val].begin(), pos[val].end(), l);
        auto index_r = upper_bound(pos[val].begin(), pos[val].end(), r);
        return index_r - index_l;
    }

    struct SEG{
        vector<int> tree;
        int n;
        MajorityChecker* checker;

        SEG(int _n, MajorityChecker* _checker): n(_n), checker(_checker), tree(vector<int>(_n * 4, 0)) {}

        pair<int, int> getMaj(int l, int r, int root, int ql, int qr){
            // l and r are range of the INPUT ARRAY
            // ql and qr are range of the QUERY
            if (l > qr || r < ql) return make_pair(0, 0);
            if (ql <= l && qr >= r){ // l and r
                if (tree[root] == 0) return make_pair(0, 0);
                int count = checker->getOccurrence(tree[root], ql, qr);
                if (count * 2 > qr - ql + 1) return make_pair(tree[root], count);
                else return make_pair(0, 0);
            }
            int mid = (l + r) >> 1;
            pair<int, int> result_l = getMaj(l, mid, root * 2, ql, qr);
            if (result_l.first > 0) return result_l;
            pair<int, int> result_r = getMaj(mid+1, r, root * 2 + 1, ql, qr);
            if (result_r.first > 0) return result_r;
            return make_pair(0, 0);
        }

        void update(int l, int r, int root){
            // both l and r are inclusive indexes of the INPUT ARRAY
            // need to use top-down update and query
            // the reason is we can keep l and r
            if (l == r){
                tree[root] = checker->array[l];
                return;
            }
            int mid = (l + r) >> 1;
            update(l, mid, root * 2);
            update(mid + 1, r, root * 2 + 1);
            if (tree[root * 2 + 1] != 0 && checker->getOccurrence(tree[root * 2 + 1], l, r) * 2 > r - l + 1)
                tree[root] = tree[root * 2 + 1];
            else if (tree[root * 2] != 0 && checker->getOccurrence(tree[root * 2], l, r) * 2 > r - l + 1)
                tree[root] = tree[root * 2];
        }
    };

    unordered_map<int, vector<int>> pos;
    SEG seg;
    vector<int> array;

    MajorityChecker(vector<int>& arr): array(arr), seg(arr.size(), this) { 
        int n = arr.size();
        for (int i=0; i<arr.size(); i++){
            if (pos.count(arr[i]) == 0) pos[arr[i]] = {i};
            else pos[arr[i]].push_back(i);
        }
        seg.update(0, n-1, 1);
    }
    
    int query(int left, int right, int threshold) {
        pair<int, int> ans = seg.getMaj(0, array.size() - 1, 1, left, right);
        if (ans.second >= threshold) return ans.first;
        else return -1;
    }

};

// /**
//  * Your MajorityChecker object will be instantiated and called as such:
//  * MajorityChecker* obj = new MajorityChecker(arr);
//  * int param_1 = obj->query(left,right,threshold);
//  */

// class MajorityChecker {
// public:

//     int getOccurrence(int val, int l, int r){
//         auto index_l = lower_bound(pos[val].begin(), pos[val].end(), l);
//         auto index_r = upper_bound(pos[val].begin(), pos[val].end(), r);
//         return index_r - index_l;
//     }

//     struct SEG{
//         vector<int> tree;
//         int n;
//         MajorityChecker* checker;

//         SEG(int _n, MajorityChecker* _checker): checker(_checker) {
//             n = 1;
//             while (n < _n) n *= 2;
//             tree = vector<int>(n*2, 0);
//         }

//         pair<int, int> getMaj(int l, int r){
//             l += n, r += n;
//             while (l <= r){
//                 if (l % 2 == 1){
//                     int l_range = l, r_range = l;
//                     while (2 * l_range < 2 * n) l_range = 2 * l_range;
//                     while (2 * r_range + 1 < 2 * n) r_range = 2 * r_range + 1;
//                     int count = checker->getOccurrence(tree[l], l_range - n, r_range - n);
//                     if (count * 2 > r - l + 1) return make_pair(tree[l], count);
//                     l += 1;
//                 }
//                 if (r % 2 == 0){
//                     int l_range = r, r_range = r;
//                     while (2 * l_range < 2 * n) l_range = 2 * l_range;
//                     while (2 * r_range + 1 < 2 * n) r_range = 2 * r_range + 1;
//                     int count = checker->getOccurrence(tree[r], l_range - n, r_range - n);
//                     if (count * 2 > r - l + 1) return make_pair(tree[r], count);
//                     r += 1;
//                 }
//                 l /= 2;
//                 r /= 2;
//             }
//             return make_pair(0, 0);
//         }

//         void update(int idx, int val){
//             idx += n;
//             tree[idx] = val;
//             for (int i=idx/2; i>0; i/=2){
//                 int l = i, r = i;
//                 while (2 * l < 2 * n) l = 2 * l;
//                 while (2 * r + 1 < 2 * n) r = 2 * r + 1;
//                 if (tree[2 * i] > 0 && checker->getOccurrence(tree[2 * i], l - n, r - n)  * 2 > r - l + 1){
//                     tree[i] = tree[2 * i];
//                 }
//                 if (tree[2 * i + 1] > 0 && checker->getOccurrence(tree[2 * i + 1], l - n, r - n) * 2 > r - l + 1){
//                     tree[i] = tree[2 * i + 1];
//                 }
//             }
//         }
//     };

//     unordered_map<int, vector<int>> pos;
//     SEG seg;
//     vector<int> array;

//     MajorityChecker(vector<int>& arr): array(arr), seg(arr.size(), this) { 
//         int n = arr.size();
//         for (int i=0; i<arr.size(); i++){
//             if (pos.count(arr[i]) == 0) pos[arr[i]] = {i};
//             else pos[arr[i]].push_back(i);
//         }
//         for (int i=0; i<n; i++) seg.update(i, arr[i]);
//     }
    
//     int query(int left, int right, int threshold) {
//         pair<int, int> ans = seg.getMaj(left, right);
//         if (ans.second >= threshold) return ans.first;
//         else return -1;
//     }

// };

int main(){
    vector<int> arr = {1,1,2,2,1,1};
    MajorityChecker* obj = new MajorityChecker(arr);
    cout << obj->query(0, 5, 4) << endl;
    cout << obj->query(0, 3, 3) << endl;
    cout << obj->query(2, 3, 2) << endl;
    return 0;
}