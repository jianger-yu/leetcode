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
class Solution {
public:
    int sum;
    bool key = false;
    void dfs(TreeNode* node, int val){
        if(key) return;
        if(node->left == node->right && node -> left == NULL){
            if(val == sum) key = true;
            return;
        }
        if(node -> left != NULL) dfs(node -> left, val + node -> left -> val);
        if(node -> right != NULL) dfs(node -> right, val + node -> right -> val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        sum = targetSum;
        dfs(root, root->val);
        return key;
    }
};