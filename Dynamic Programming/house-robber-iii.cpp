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

    struct DPNode {
        int st, nst;
        DPNode *left;
        DPNode *right;
        DPNode() : st(0), nst(0), left(nullptr), right(nullptr) {}
        DPNode(int x, int y) : st(x), nst(y), left(nullptr), right(nullptr) {}
        DPNode(int x, int y, DPNode *left, DPNode *right) : st(x), nst(y), left(left), right(right) {}
    };

    int rob(TreeNode* root) {
        DPNode* dp = new DPNode();
        search_tree(root, dp);
        return max(dp->st, dp->nst);
    }

    void search_tree(TreeNode* tree, DPNode* dp) {
        if (tree->left != nullptr) {
            dp->left = new DPNode();
            search_tree(tree->left, dp->left);
        }
        if (tree->right != nullptr){
            dp->right = new DPNode();
            search_tree(tree->right, dp->right);
        }
        if (tree->left == nullptr && tree->right == nullptr){
            dp->nst = 0;
            dp->st = tree->val;
        } else{ 
            dp->st = tree->val;
            int max_val = 0;
            if (tree->left != nullptr){
                dp->nst += max(dp->left->nst, dp->left->st);
                if (tree->left->left != nullptr) max_val += max(dp->left->left->st, dp->left->left->nst);
                if (tree->left->right != nullptr) max_val += max(dp->left->right->st, dp->left->right->nst);
            } 
            if (tree->right != nullptr){
                dp->nst += max(dp->right->nst, dp->right->st);
                if (tree->right->left != nullptr) max_val += max(dp->right->left->st, dp->right->left->nst);
                if (tree->right->right != nullptr) max_val += max(dp->right->right->st, dp->right->right->nst);
            }
            dp->st += max_val;
        }
    }
};

int main(){
    Solution sol;
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);
    // cout << sol.rob(root) << endl;
    // use this case [4,1,null,2,null,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    cout << sol.rob(root) << endl;
    return 0;
}