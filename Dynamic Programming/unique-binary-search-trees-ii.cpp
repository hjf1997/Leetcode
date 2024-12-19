#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  
    vector<TreeNode*> generateTrees(int n) {
        return buildTrees(0, n-1);
    }

    vector<TreeNode*> buildTrees(int start, int end){
        vector<TreeNode*> trees;
        if (start > end){
            trees.push_back(nullptr);
            return trees;
        }

        for (int i=start; i<=end; i++){
            vector<TreeNode*> left_trees = buildTrees(start, i-1);
            vector<TreeNode*> right_trees = buildTrees(i+1, end);

            for (int l=0; l<left_trees.size(); l++)
                for (int r=0; r<right_trees.size(); r++){
                    trees.push_back(new TreeNode(i+1, left_trees[l], right_trees[r]));
                }
        }
        return trees;
    }
};

int main(){
    Solution sol;
    vector<TreeNode*> trees = sol.generateTrees(1);
    // print trees
    cout << trees.size() << endl;
    return 0;
}