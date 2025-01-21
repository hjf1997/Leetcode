#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     struct Node{
//         int num;
//         Node *next;
//     };

//     vector<int> processQueries(vector<int>& queries, int m) {
//         // O(N^2) version
//         Node* head = new Node();
//         Node* current = head;
//         vector<int> ans;
//         for (int i=1; i<=m; i++){
//             current->num = i;
//             current->next = new Node();
//             current = current->next;
//         }

//         for (int q: queries){
//             // search
//             Node* b_target = head;
//             if (b_target->num == q) ans.push_back(0);
//             else{
//                 int position = 1;
//                 while (b_target->next != nullptr){
//                     if (b_target->next->num == q) break;
//                     else{
//                         b_target = b_target->next;
//                         position += 1;
//                     }
//                 }
//                 Node* target = b_target->next;
//                 b_target->next = b_target->next->next;
//                 target->next = head;
//                 head = target;
//                 ans.push_back(position);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> BIT;
    int length;

    vector<int> processQueries(vector<int>& queries, int m) {
        // O(NLogN) version / Binary Indexed Tree
        vector<int> ans;
        length = 2*m;
        BIT = vector<int>(2*m+1, 0);
        int ins_pos = m;
        unordered_map<int, int> pos;
        for (int i=m+1; i<=2*m+1; i++){
            update(i, 1);
            pos[i-m] = i;
        }

        for (int q: queries){
            ans.push_back(getPos(pos[q])-1);
            update(ins_pos, 1);
            update(pos[q], -1);
            pos[q] = ins_pos;
            ins_pos -= 1;
        }
        return ans;
    }

    void update(int idx, int val){
        for (int i=idx; i<=length; i+=(i&-i)) BIT[i] += val;
    }

    int getPos(int idx){
        int pos = 0;
        for (int i=idx; i>=1; i-=(i&-i)) pos += BIT[i];
        return pos;
    }
};

int main(){
    Solution sol;
    vector<int> queries = {7,5,5,8,3};
    int m = 8;
    vector<int> ans = sol.processQueries(queries, m);
    for (int a: ans) cout << a << " ";
    cout << endl;
    return 0;
}